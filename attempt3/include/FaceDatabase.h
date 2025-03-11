#ifndef FACEDATABASE_H
#define FACEDATABASE_H

#include <dlib/matrix.h>
#include <string>
#include <vector>
#include <utility>
#include <fstream>


class FaceDatabase {
public:
    void addFace(const std::string& label, const dlib::matrix<float, 0, 1>& descriptor);
    std::pair<std::string, double> findClosestMatch(const dlib::matrix<float, 0, 1>& descriptor, double threshold = 0.6) const;

    void saveDatabase(const std::string& filename) const;
    void loadDatabase(const std::string& filename);

private:
    std::vector<std::pair<std::string, dlib::matrix<float, 0, 1>>> faces;
};

#endif
