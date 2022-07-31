# CMakeList.txt: проект CMake для Break_Out_Game; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# force Unicode over Multi-byte
add_definitions(-DUNICODE -D_UNICODE)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (Break_Out_Game "Breakout_Game.cpp" "Breakout_Game.h" "GameBaseClass.h" "Breakout.cpp" "Breakout.h" "GameBaseClass.cpp" "SpriteClass.h" "SpriteClass.cpp" "engine_constants.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
