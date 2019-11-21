cmake_minimum_required(VERSION 3.15)
project(src)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "-Wall ")
set(CMAKE_CXX_FLAGS_DEBUG "-g ${CMAKE_CXX_FLAGS_DEBUG}")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 ${CMAKE_CXX_FLAGS_RELEASE}")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

add_executable(src
        main.cpp
        Tsp/CostMatrix.cpp
        Tsp/CostMatrix.h
        Cli/GenericCli.cpp
        Cli/GenericCli.h
        Tsp/TSP.cpp
        Tsp/TSP.h
        Tsp/Route.cpp
        Tsp/Route.h
        Tsp/Solver/Dynamic/DynamicProg.cpp
        Tsp/Solver/Dynamic/DynamicProg.h
        Tsp/Solver/BruteForce/BruteForce.cpp
        Tsp/Solver/BruteForce/BruteForce.h
        Tsp/Solver/BranchAndBound/BranchAndBound.cpp
        Tsp/Solver/BranchAndBound/BranchAndBound.h
        Utils/UniformRand.cpp
        Utils/UniformRand.h
        Tsp/Solver/GenericSolver.cpp
        Tsp/Solver/GenericSolver.h
        Tsp/Solver/BranchAndBound/PartSolution.cpp Tsp/Solver/BranchAndBound/PartSolution.h Tsp/Solver/BranchAndBound/PartSolutionComparator.cpp Tsp/Solver/BranchAndBound/PartSolutionComparator.h Tsp/Constants.h Utils/PrintUtils.cpp Utils/PrintUtils.h Tsp/Solver/Solvers.h Cli/TspMainMenu.cpp Cli/TspMainMenu.h Cli/SubMenus/TspLoadMenu.cpp Cli/SubMenus/TspLoadMenu.h Cli/SubMenus/TspSolveMenu.cpp Cli/SubMenus/TspSolveMenu.h Cli/GenericTspCli.cpp Cli/GenericTspCli.h Utils/Stopwatch.cpp Utils/Stopwatch.h Benchmark/Tester/Tester.cpp Benchmark/Tester/Tester.h Benchmark/Benchmark.h Benchmark/Benchmark.cpp Utils/InputParser.cpp Utils/InputParser.h)