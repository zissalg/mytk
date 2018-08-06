cmake_minimum_required(VERSION 3.11)
project(RescueGlassiz)

set(SOURCES_FOLDER "src/")
set(SOURCE_FILES "")
set(LINK_LIBS -lSDL2 -lSDL2_image -lSDL2_ttf)

aux_source_directory(${SOURCES_FOLDER} SOURCE_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${LINK_LIBS})
