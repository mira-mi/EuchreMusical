# CMakeList.txt : CMake project for euchrethemusical, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (euchrethemusical "euchrethemusical.cpp" "euchrethemusical.h" "deck.h" "deck.cpp" "play.h" "play.cpp"      "checkcards.h" "checkcards.cpp" "gamerounds.h"  "gamerounds.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET euchrethemusical PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
