# CMakeList.txt: CMake-Projekt für "MathLib". Schließen Sie die Quelle ein, und definieren Sie
# projektspezifische Logik hier.
#
cmake_minimum_required (VERSION 3.8)

# Fügen Sie der ausführbaren Datei dieses Projekts eine Quelle hinzu.
add_executable (MathLib "MathLib.cpp" "MathLib.h" "Vector/Vector.h" "Vector/Vector.cpp" "matrix/Matrix.h" "matrix/Matrix.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET MathLib PROPERTY CXX_STANDARD 20)
endif()

# TODO: Fügen Sie bei Bedarf Tests hinzu, und installieren Sie Ziele.
