# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)

# force Unicode over Multi-byte

add_definitions(-DUNICODE -D_UNICODE)

project ("Break_Out_Game")

# Включите подпроекты.
add_subdirectory ("Break_Out_Game")
