cmake_minimum_required(VERSION 3.26)
project(dataStructureAndAlgorithms)

set(CMAKE_CXX_STANDARD 17)

add_executable(dataStructureAndAlgorithms main.cpp
        LinearList/linearList.h
        LinearList/linearList.cpp
        LinkList/linkList.h
        LinkList/linkList.cpp
        UnivariatePolynomial/Polynomial.h
        UnivariatePolynomial/Polynomial.cpp
        LinearList/testLinearList.cpp
        LinkList/testLinkList.cpp
        LinearStack/linearStack.h
        LinearStack/stack.cpp
        LinearStack/testLinearStack.cpp
        LinkStack/linkStack.h
        LinkStack/stack.cpp
        LinkStack/testLinkStack.cpp
        queue/Queue.h
        queue/Queue.cpp
        queue/testQueue.cpp
#        " DiscreteSimulation/discreteSimulation.cpp"
        QueueSimulation/CPUSimulation.cpp
        QueueSimulation/CPUSimulation.cpp
        QueueSimulation/discreteSimulation.cpp
#        String/string.h
        GeneralizedList/glistList.h
        GeneralizedList/glistList.h
        GeneralizedList/glistList.h
        Tree/BinaryTree.h
        Tree/BinaryTree.cpp
        Tree/testBinaryTree.cpp
)
