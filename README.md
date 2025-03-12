# Real-Time Face Recognition with OpenCV and Dlib

This project is a real-time face recognition system using OpenCV and Dlib. It captures video from the webcam, detects faces in real-time, and compares them to a pre-existing database of known faces using a deep learning model. The system also allows for enrolling new faces and saving the updated face database.

    Key Features:

    Real-time face detection and recognition.
    Face enrollment and database management.
    Uses OpenCV for video capture and face detection (Haar Cascade).
    Uses Dlib's ResNet model for face recognition.
    Display results with matching names and recognition confidence scores.

### Requirements

Before running this project, ensure you have the following:

    OpenCV: A computer vision library for video capture and face detection.
    Dlib: A toolkit for machine learning and computer vision, which includes a pre-trained ResNet face recognition model.
    C++ Compiler: A C++11-compliant compiler (e.g., GCC, MSVC).

Install Dependencies:

To get started, you will need to install OpenCV and Dlib on your system. You can follow the official installation guides for each:

OpenCV: [OpenCV Installation Guide](https://docs.opencv.org/4.x/d3/d52/tutorial_windows_install.html)
Dlib: [Dlib Installation Guide](https://dlib.net/)

Pre-trained Models:

    Haar Cascade for face detection: You need to download the pre-trained Haar Cascade file for frontal face detection (haarcascade_frontalface_default.xml). You can get it from the OpenCV GitHub repository.
    Dlib ResNet Model: You need to download the pre-trained ResNet model for face recognition (dlib_face_recognition_resnet_model_v1.dat). You can download it from the Dlib model repository.

Make sure to place these models in the appropriate directories as described below.
How to Run the Project:

1. Clone the repository

git clone https://github.com/LouisNight/criminal-database-face-scanner.git
cd criminal-database-face-scanner

2. Configure Model Paths

In the code, static paths are used for both the Haar Cascade and ResNet model files. You will need to change these paths to match where you store the files on your local machine.

    Haar Cascade file: Change the path in the main.cpp file to point to the location of the haarcascade_frontalface_default.xml file.

Example:

FaceDetector detector("path/to/your/haarcascade_frontalface_default.xml");

ResNet model file: Change the path in the FaceRecognizer constructor to point to the location of the dlib_face_recognition_resnet_model_v1.dat file.

Example:

    FaceRecognizer recognizer("path/to/your/dlib_face_recognition_resnet_model_v1.dat");

3. Build the Project
Using Visual Studio 2022:

    Open the solution file (.sln) in Visual Studio.
    Make sure to configure the include directories and library directories to point to where OpenCV and Dlib are installed.
    Build the project in x64-Debug mode.

Using CMake:

    Create a build directory and navigate into it.

    Run the following commands:

    cmake ..
    make

4. Run the Project

Once the project is built, you can run the program. It will open a window showing the webcam feed, and you will be able to:

    Press 'n' to enroll a new face (add it to the face database).
    Press 's' to save the updated database.
    Press 'q' to quit the program.

The program will automatically detect faces in the video feed, show the name of the detected person if a match is found, and display the recognition confidence score.

How to Enroll a New Face:

When pressing 'n' to enroll a new face, you will be prompted to enter a name for the person. The face's feature descriptor will then be saved to the face database.

Make sure the face is well-lit and facing the camera for better recognition accuracy.

    Ensure your webcam is accessible, and no other application is using it while running the program.
    Face recognition accuracy may vary depending on the quality of the webcam and the faces detected.
