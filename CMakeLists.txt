cmake_minimum_required(VERSION 3.29)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED On)

project(
    leetcode 
    LANGUAGES CXX
)

function(PROBLEM NUMBER)
    add_executable(
        "${NUMBER}" 
        "${NUMBER}.cc"
    )
endfunction()

problem(1460)
problem(1508)
problem(2053)
problem(3016)
problem(1535)
problem(273)
problem(840)
problem(885)
problem(959)
problem(1568)
problem(703)
problem(2092)
problem(40)
problem(213)
problem(719)
problem(9)
problem(13)
problem(14)
problem(58)
problem(66)
problem(624)
problem(80)
problem(1937)
problem(264)
problem(650)
problem(1971)
problem(1140)
problem(983)
