#include "..\include\FaceDatabase.h"
#include <limits>
#include <cmath>
#include <iostream>


void FaceDatabase::addFace(const std::string& label, const dlib::matrix<float, 0, 1>& descriptor)
{
    faces.push_back({ label, descriptor });
    std::cout << "Added " << label << " to database.\n";
}


std::pair<std::string, double> FaceDatabase::findClosestMatch(const dlib::matrix<float, 0, 1>& descriptor, double threshold) const
{
    std::string bestLabel = "unknown";
    double bestDistance = std::numeric_limits<double>::max();

    for (const auto& face : faces)
    {
        double distance = length(face.second - descriptor);
        if (distance < bestDistance)
        {
            bestDistance = distance;
            bestLabel = face.first;
        }
    }
   
    return (bestDistance < threshold) ? std::make_pair(bestLabel, bestDistance) : std::make_pair("unknown", bestDistance);
}

// database to file
void FaceDatabase::saveDatabase(const std::string& filename) const
{
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error: Could not open file for writing.\n";
        return;
    }

    size_t count = faces.size();
    file.write(reinterpret_cast<const char*>(&count), sizeof(count));

    for (const auto& face : faces) {
        size_t labelSize = face.first.size();
        file.write(reinterpret_cast<const char*>(&labelSize), sizeof(labelSize));
        file.write(face.first.data(), labelSize);

        for (long i = 0; i < 128; ++i)
            file.write(reinterpret_cast<const char*>(&face.second(i)), sizeof(float));
    }

    std::cout << "Database saved.\n";
}

// database from file
void FaceDatabase::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Warning: No existing database found. Starting new.\n";
        return;
    }

    size_t count;
    file.read(reinterpret_cast<char*>(&count), sizeof(count));

    faces.clear();
    for (size_t i = 0; i < count; ++i) {
        size_t labelSize;
        file.read(reinterpret_cast<char*>(&labelSize), sizeof(labelSize));

        std::string label(labelSize, '\0');
        file.read(&label[0], labelSize);

        dlib::matrix<float, 0, 1> descriptor(128);
        for (long j = 0; j < 128; ++j)
            file.read(reinterpret_cast<char*>(&descriptor(j)), sizeof(float));

        faces.push_back({ label, descriptor });
    }

    std::cout << "Database loaded with " << faces.size() << " faces.\n";
}
