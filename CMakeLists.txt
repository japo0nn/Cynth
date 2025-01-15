cmake_minimum_required(VERSION 3.10)

project(CynthCompiler)

# Устанавливаем стандарт C
set(CMAKE_C_STANDARD 99)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Добавляем директорию с заголовочными файлами
include_directories(include)

# Указываем исходные файлы
add_executable(CynthCompiler src/main.c src/sha256.c)

