cmake_minimum_required(VERSION 3.26)
project(dataStructureAndAlgorithms)

set(CMAKE_CXX_STANDARD 17)

add_executable(dataStructureAndAlgorithms main.cpp
        线性表/LinearList/linearList.h
        线性表/LinearList/linearList.cpp
        线性表/LinkList/linkList.h
        线性表/LinkList/linkList.cpp
        线性表/UnivariatePolynomial/Polynomial.h
        线性表/UnivariatePolynomial/Polynomial.cpp
        线性表/LinearList/testLinearList.cpp
        线性表/LinkList/testLinkList.cpp
        栈/LinearStack/linearStack.h
        栈/LinearStack/stack.cpp
        栈/LinearStack/testLinearStack.cpp
        栈/LinkStack/linkStack.h
        栈/LinkStack/stack.cpp
        栈/LinkStack/testLinkStack.cpp
        队列/queue/Queue.h
        队列/queue/Queue.cpp
        队列/queue/testQueue.cpp
#        " DiscreteSimulation/discreteSimulation.cpp"
        队列/QueueSimulation/CPUSimulation.cpp
        队列/QueueSimulation/CPUSimulation.cpp
        队列/QueueSimulation/discreteSimulation.cpp
#        String/string.h
        广义表/GeneralizedList/glistList.h
        广义表/GeneralizedList/glistList.h
        广义表/GeneralizedList/glistList.h
        树与二叉树/Tree/BinaryTree.h
        树与二叉树/Tree/BinaryTree.cpp
        树与二叉树/Tree/testBinaryTree.cpp
        串/KMP算法/KMP.h
        串/KMP算法/KMP.h
        串/KMP算法/KMP.cpp
        串/KMP算法/testKMP.cpp
)
