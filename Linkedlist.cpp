<?xml version="1.0" encoding="utf-8"?>
<Project DefaultTargets="Build" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">
  <ItemGroup Label="ProjectConfigurations">
    <ProjectConfiguration Include="Debug|Win32">
      <Configuration>Debug</Configuration>
      <Platform>Win32</Platform>
    </ProjectConfiguration>
    <ProjectConfiguration Include="Release|Win32">
      <Configuration>Release</Configuration>
      <Platform>Win32</Platform>
    </ProjectConfiguration>
    <ProjectConfiguration Include="Debug|x64">
      <Configuration>Debug</Configuration>
      <Platform>x64</Platform>
    </ProjectConfiguration>
    <ProjectConfiguration Include="Release|x64">
      <Configuration>Release</Configuration>
      <Platform>x64</Platform>
    </ProjectConfiguration>
  </ItemGroup>
  <ItemGroup>
    <ClCompile Include="DoublyLinkedlist.cpp" />
    <ClCompile Include="Linkedlist.cpp" />
  </ItemGroup>
  <PropertyGroup Label="Globals">
    <VCProjectVersion>17.0</VCProjectVersion>
    <Keyword>Win32Proj</Keyword>
    <ProjectGuid>{e5cb7d55-6a6e-478d-9a80-ac52e143dfc9}</ProjectGuid>
    <RootNamespace>My24120409</RootNamespace>
    <WindowsTargetPlatformVersion>10.0</WindowsTargetPlatformVersion>
  </PropertyGroup>
  <Import Project="$(VCTargetsPath)\Microsoft.Cpp.Default.props" />
  <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'" Label="Configuration">
    <ConfigurationType>Application</ConfigurationType>
    <UseDebugLibraries>true</UseDebugLibraries>
    <PlatformToolset>v143</PlatformToolset>
    <CharacterSet>Unicode</CharacterSet>
  </PropertyGroup>
  <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Release|Win32'" Label="Configuration">
    <ConfigurationType>Application</ConfigurationType>
    <UseDebugLibraries>false</UseDebugLibraries>
    <PlatformToolset>v143</PlatformToolset>
    <WholeProgramOptimization>true</WholeProgramOptimization>
    <CharacterSet>Unicode</CharacterSet>
  </PropertyGroup>
  <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Debug|x64'" Label="Configuration">
    <ConfigurationType>Application</ConfigurationType>
    <UseDebugLibraries>true</UseDebugLibraries>
    <PlatformToolset>v143</PlatformToolset>
    <CharacterSet>Unicode</CharacterSet>
  </PropertyGroup>
  <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Release|x64'" Label="Configuration">
    <ConfigurationType>Application</ConfigurationType>
    <UseDebugLibraries>false</UseDebugLibraries>
    <PlatformToolset>v143</PlatformToolset>
    <WholeProgramOptimization>true</WholeProgramOptimization>
    <CharacterSet>Unicode</CharacterSet>
  </PropertyGroup>
  <Import Project="$(VCTargetsPath)\Microsoft.Cpp.props" />
  <ImportGroup Label="ExtensionSettings">
  </ImportGroup>
  <ImportGroup Label="Shared">
  </ImportGroup>
  <ImportGroup Label="PropertySheets" Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'">
    <Import Project="$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props" Condition="exists('$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props')" Label="LocalAppDataPlatform" />
  </ImportGroup>
  <ImportGroup Label="PropertySheets" Condition="'$(Configuration)|$(Platform)'=='Release|Win32'">
    <Import Project="$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props" Condition="exists('$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props')" Label="LocalAppDataPlatform" />
  </ImportGroup>
  <ImportGroup Label="PropertySheets" Condition="'$(Configuration)|$(Platform)'=='Debug|x64'">
    <Import Project="$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props" Condition="exists('$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props')" Label="LocalAppDataPlatform" />
  </ImportGroup>
  <ImportGroup Label="PropertySheets" Condition="'$(Configuration)|$(Platform)'=='Release|x64'">
    <Import Project="$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props" Condition="exists('$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props')" Label="LocalAppDataPlatform" />
  </ImportGroup>
  <PropertyGroup Label="UserMacros" />
  <ItemDefinitionGroup Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'">
    <ClCompile>
      <WarningLevel>Level3</WarningLevel>
      <SDLCheck>true</SDLCheck>
      <PreprocessorDefinitions>WIN32;_DEBUG;_CONSOLE;%(PreprocessorDefinitions)</PreprocessorDefinitions>
      <ConformanceMode>true</ConformanceMode>
    </ClCompile>
    <Link>
      <SubSystem>Console</SubSystem>
      <GenerateDebugInformation>true</GenerateDebugInformation>
    </Link>
  </ItemDefinitionGroup>
  <ItemDefinitionGroup Condition="'$(Configuration)|$(Platform)'=='Release|Win32'">
    <ClCompile>
      <WarningLevel>Level3</WarningLevel>
      <FunctionLevelLinking>true</FunctionLevelLinking>
      <IntrinsicFunctions>true</IntrinsicFunctions>
      <SDLCheck>true</SDLCheck>
      <PreprocessorDefinitions>WIN32;NDEBUG;_CONSOLE;%(PreprocessorDefinitions)</PreprocessorDefinitions>
      <ConformanceMode>true</ConformanceMode>
    </ClCompile>
    <Link>
      <SubSystem>Console</SubSystem>
      <EnableCOMDATFolding>true</EnableCOMDATFolding>
      <OptimizeReferences>true</OptimizeReferences>
      <GenerateDebugInformation>true</GenerateDebugInformation>
    </Link>
  </ItemDefinitionGroup>
  <ItemDefinitionGroup Condition="'$(Configuration)|$(Platform)'=='Debug|x64'">
    <ClCompile>
      <WarningLevel>Level3</WarningLevel>
      <SDLCheck>true</SDLCheck>
      <PreprocessorDefinitions>_DEBUG;_CONSOLE;%(PreprocessorDefinitions)</PreprocessorDefinitions>
      <ConformanceMode>true</ConformanceMode>
    </ClCompile>
    <Link>
      <SubSystem>Console</SubSystem>
      <GenerateDebugInformation>true</GenerateDebugInformation>
    </Link>
  </ItemDefinitionGroup>
  <ItemDefinitionGroup Condition="'$(Configuration)|$(Platform)'=='Release|x64'">
    <ClCompile>
      <WarningLevel>Level3</WarningLevel>
      <FunctionLevelLinking>true</FunctionLevelLinking>
      <IntrinsicFunctions>true</IntrinsicFunctions>
      <SDLCheck>true</SDLCheck>
      <PreprocessorDefinitions>NDEBUG;_CONSOLE;%(PreprocessorDefinitions)</PreprocessorDefinitions>
      <ConformanceMode>true</ConformanceMode>
    </ClCompile>
    <Link>
      <SubSystem>Console</SubSystem>
      <EnableCOMDATFolding>true</EnableCOMDATFolding>
      <OptimizeReferences>true</OptimizeReferences>
      <GenerateDebugInformation>true</GenerateDebugInformation>
    </Link>
  </ItemDefinitionGroup>
  <Import Project="$(VCTargetsPath)\Microsoft.Cpp.targets" />
  <ImportGroup Label="ExtensionTargets">
  </ImportGroup>
</Project>﻿<?xml version="1.0" encoding="utf-8"?>
<Project ToolsVersion="4.0" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">
  <ItemGroup>
    <Filter Include="Source Files">
      <UniqueIdentifier>{4FC737F1-C7A5-4376-A066-2A32D752A2FF}</UniqueIdentifier>
      <Extensions>cpp;c;cc;cxx;c++;cppm;ixx;def;odl;idl;hpj;bat;asm;asmx</Extensions>
    </Filter>
    <Filter Include="Header Files">
      <UniqueIdentifier>{93995380-89BD-4b04-88EB-625FBE52EBFB}</UniqueIdentifier>
      <Extensions>h;hh;hpp;hxx;h++;hm;inl;inc;ipp;xsd</Extensions>
    </Filter>
    <Filter Include="Resource Files">
      <UniqueIdentifier>{67DA6AB6-F800-4c08-8B7A-83BB121AAD01}</UniqueIdentifier>
      <Extensions>rc;ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe;resx;tiff;tif;png;wav;mfcribbon-ms</Extensions>
    </Filter>
  </ItemGroup>
  <ItemGroup>
    <ClCompile Include="Linkedlist.cpp">
      <Filter>Source Files</Filter>
    </ClCompile>
    <ClCompile Include="DoublyLinkedlist.cpp">
      <Filter>Source Files</Filter>
    </ClCompile>
  </ItemGroup>
</Project>﻿<?xml version="1.0" encoding="utf-8"?>
<Project ToolsVersion="Current" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">
  <PropertyGroup />
</Project>#include <iostream>
#include <cassert>
struct d_NODE
{
    int key;
    d_NODE* pPrev;
    d_NODE* pNext;
};

struct d_List
{
    d_NODE *pHead;
    d_NODE *pTail;
    d_List(d_NODE *head = nullptr, d_NODE *tail = nullptr) : pHead(head), pTail(tail) {}
};

// --- Define function prototypes ---
d_NODE *createNode(int data);
d_List* createList(d_NODE* p_node);
bool addHead(d_List *&L, int data);
bool addTail(d_List *&L, int data);
bool removeHead(d_List *&L);
void removeTail(d_List *&L);
void removeAll(d_List *&L);
void removeBefore(d_List *&L, int val);
void removeAfter(d_List *&L, int val);
bool addPos(d_List *&L, int data, int pos);
void removePos(d_List *&L, int data, int pos);
bool addBefore(d_List *&L, int data, int val);
bool addAfter(d_List *&L, int data, int val);
void printList(d_List *L);
int countElements(d_List *L);
d_List *reverseList(d_List *L);
void removeDuplicate(d_List *&L);
bool removeElement(d_List *&L, int key);

// function to create a list from an array
d_List *createListFromArray(int arr[], int n)
{
    d_List *newList = new d_List();
    newList->pHead = nullptr;
    newList->pTail = nullptr;
    for (int i = 0; i < n; ++i)
    {
        addTail(newList, arr[i]);
    }
    return newList;
}

// function to compare two lists
bool areListsEqual(d_List *list1, d_List *list2)
{
    d_NODE *current1 = list1 ? list1->pHead : nullptr;
    d_NODE *current2 = list2 ? list2->pHead : nullptr;
    while (current1 && current2)
    {
        if (current1->key != current2->key)
        {
            return false;
        }
        current1 = current1->pNext;
        current2 = current2->pNext;
    }
    return (current1 == nullptr && current2 == nullptr);
}

// function to free the memory of a list
void freeList(d_List *L)
{
    d_NODE *current = L->pHead;
    while (current)
    {
        d_NODE *next = current->pNext;
        delete current;
        current = next;
    }
    delete L;
}

d_NODE *createNode(int data)
{
    // Allocate a New Node
    d_NODE* newNode = new d_NODE;
    // Out of Space for Allocation
    if (newNode == nullptr)
        return nullptr;

    // Getting information for the Node
    newNode->pNext = newNode->pPrev = nullptr;
    newNode->key = data;

    return newNode; // Placeholder return statement
}

d_List *createList(d_NODE *p_node)
{
    // cannot Creat List from a nullptr Node
    if (p_node == nullptr)
        return nullptr;

    // Create a List
    d_List* list = new d_List;
    list->pHead = list->pTail = p_node;

    return list; // Placeholder return statement
}

bool addHead(d_List *&L, int data)
{
    // List doens't exist
    if (L == nullptr)
        return 0;

    // Create a New Node
    d_NODE* add = createNode(data);

    // Adding Head to an Empty List
    if (L->pHead == nullptr)
    {
        L->pHead = L->pTail = add;
    }
    // Adding head to a normal List
    else
    {
        // Linked the Add Node
        add->pNext = L->pHead;
        add->pPrev = nullptr;
        // Link the old Head
        L->pHead->pPrev = add;

        L->pHead = add;
    }
    return 1;
}

bool addTail(d_List *&L, int data) // this function is kept for createListfromArray function
{
    // List doesn't exist
    if (L == nullptr)
        return 0;
    // Create a Node
    d_NODE *newNode = createNode(data);
    // Adding to an Empty List
    if (L->pHead == nullptr)
    {
        L->pHead = newNode;
        L->pTail = newNode;
    }
    // Normal Cases
    else
    {
        // Link the NewNode
        newNode->pNext = nullptr;
        newNode->pPrev = L->pTail;

        // Get new Node as Tail Node
        L->pTail->pNext = newNode;
        L->pTail = newNode;
    }
    return 1;
}

bool removeHead(d_List *&L)
{
    // List doesn't exist || Empty List
    if (L == nullptr || L->pHead == nullptr)
        return 0;

    d_NODE* del = L->pHead;

    // List has One Node left
    if (L->pHead->pNext == nullptr)
    {
        delete del;
        L->pHead = L->pTail = nullptr;
    }
    // Normal Case
    else
    {
        // Move the Head to the next Node
        L->pHead = L->pHead->pNext;
        L->pHead->pPrev = nullptr;

        delete del;
    }
    return 1;
}

void removeTail(d_List *&L)
{
    // List doesn't exist || Empty List
    if (L == nullptr || L->pTail == nullptr)
        return;

    d_NODE* del = L->pTail;
    // List has One Node left
    if (L->pTail->pPrev == nullptr)
    {
        delete del;
        L->pHead = L->pTail = nullptr;
    }
    // Normal case
    else
    {
        // Change the Tail Node
        L->pTail = del->pPrev;
        L->pTail->pNext = nullptr;

        delete del;
    }
    return;
}

void removeAll(d_List *&L)
{
    // List doesn't exist || empty List
    if (L == nullptr || L->pHead == nullptr)
        return;

    d_NODE* tmp = L->pHead;
    // Delete the all the Node but tailNode
    while (tmp->pNext)
    {
        d_NODE* del = tmp;
        tmp = tmp->pNext;
        delete del;
    }
    // Delete the Tail Node
    delete tmp;
    // Return to empty List
    L->pHead = L->pTail = nullptr;

    return;
}

// Remove a node before a given value in the list if it exists, otherwise do nothing
void removeBefore(d_List *&L, int val)
{
    // List doesn't exist || empty List
    if (L == nullptr || L->pHead == nullptr)
        return;

    // Move to the given Key Node
    d_NODE* tmp = L->pHead;
    while (tmp && tmp->key != val)
        tmp = tmp->pNext;

    // No Key was Found in the List || No Node exists before the head Node
    if (tmp == nullptr || tmp->pPrev == nullptr)
        return;

    d_NODE* del = tmp->pPrev;
    // Fix the Link
    tmp->pPrev = del->pPrev;
    del->pPrev->pNext = tmp;

    delete del;

    return;
}

void removeAfter(d_List *&L, int val)
{
    // List doesn't exist || empty List
    if (L == nullptr || L->pHead == nullptr)
        return;

    // Move to the given Key Node
    d_NODE* tmp = L->pHead;
    while (tmp && tmp->key != val)
        tmp = tmp->pNext;

    // No Key was Found in the List || No Node exists after the Tail Node
    if (tmp == nullptr || tmp->pNext == nullptr)
        return;

    d_NODE* del = tmp->pNext;
    // Fix the Link
    tmp->pNext = del->pNext;
    if (del->pNext != nullptr) del->pNext->pPrev = tmp;

    delete del;

    return;
}

bool addPos(d_List *&L, int data, int pos)
{
    // List doesn't exist
    if (L == nullptr)
        return 0;

    // Add to Empty List
    if (L->pHead == nullptr)
    {
        
        if (pos == 0)
        {
            addHead(L, data);
            return 1;
        }
        // No more place than Head to add Node
        return 0;
    }
    
    // Moving to the specific place
    d_NODE* tmp = L->pHead;
    while (pos != 1 && tmp->pNext)
    {
        tmp = tmp->pNext;
        --pos;
    }

    // Out of Range
    if (pos != 1) return 0;

    if (tmp == L->pTail)
    {
        addTail(L, data);
        return 1;
    }

    d_NODE* add = createNode(data);
    // Link the new Node
    add->pPrev = tmp;
    add->pNext = tmp->pNext;

    // Fix the Link
    tmp->pNext->pPrev = add;
    tmp->pNext = add;

    return 1;
}

void removePos(d_List*& L, int data, int pos)
{
    // List doesn't exist || Empty List
    if (L == nullptr || L->pHead == nullptr) return;

    // Remove the head Node
    if (pos == 0)
    {
        if (L->pHead->key == data)
            removeHead(L);
        return;
    }

    // Moving to Remove postion
    d_NODE* tmp = L->pHead;
    while (pos != 1 && tmp->pNext)
    {
        tmp = tmp->pNext;
        --pos;
    }

    // Out of Range
    if (pos != 1) return;
    // Node Key value does not match value need to be deleted
    if (tmp->pNext != nullptr && tmp->pNext->key != data) return;

    // Remove the Tail Node
    if (tmp->pNext == L->pTail)
        removeTail(L);
    // Remove Normal Node
    else
    {
        d_NODE* del = tmp->pNext;
        tmp->pNext = del->pNext;
        del->pNext->pPrev = tmp;
        delete del;
    }
}

// Insert an integer before a value of a given List:
bool addBefore(d_List*& L, int data, int val)
{
    // List doesn't exist || Empty List
    if (L == nullptr || L->pHead == nullptr) return 0;
    // Adding head case
    if (L->pHead->key == val)
    {
        addHead(L, data);
        return 1;
    }

    d_NODE* tmp = L->pHead;
    while (tmp->pNext && tmp->key != val)
    {
        tmp = tmp->pNext;
    }

    // No Node with Key value equal 'val' input
    if (tmp->pNext == nullptr && tmp->key != val) return 0;

    d_NODE* add = createNode(data);

    // Link the New Node
    add->pNext = tmp;
    add->pPrev = tmp->pPrev;

    // fix the Link
    if (tmp->pPrev != nullptr)
        tmp->pPrev->pNext = add;
    tmp->pPrev = add;

    return 1;
}

bool addAfter(d_List *&L, int data, int val)
{
    // List doesn't exist || Empty List
    if (L == nullptr || L->pHead == nullptr) return 0;

    // Moving to the Adding spot
    d_NODE* tmp = L->pHead;
    while (tmp->pNext && tmp->key != val)
        tmp = tmp->pNext;

    // No Key Node with such value exists in the list
    if (tmp == L->pTail && L->pTail->key != val) return 0;
    // Adding Tail Node
    else if (tmp == L->pTail) addTail(L, data);
    // Adding Node Normally
    else
    {
        d_NODE* add = createNode(data);
        // Link the New Node
        add->pPrev = tmp;
        add->pNext = tmp->pNext;
        // Fix the Link in the List
        tmp->pNext->pPrev = add;
        tmp->pNext = add;
    }

    return 1;
}

void printList(d_List *L)
{
    // List doesn't exist || Empty List
    if (L == nullptr && L->pHead == nullptr) return;

    // Display Key value each Node in the List
    d_NODE* tmp = L->pHead;
    while (tmp)
    {
        std::cout << tmp->key << "  --->   ";
        tmp = tmp->pNext;
    }
    std::cout << "NULL\n";
}

int countElements(d_List *L)
{
    // List does not exist
    if (L == nullptr) return -1;
    // Empty List
    if (L->pHead == nullptr) return 0;

    int size = 0;
    d_NODE* tmp = L->pHead;
    while (tmp)
    {
        ++size;
        tmp = tmp->pNext;
    }

    return size;
}

d_List *reverseList(d_List *L)
{
    // List does not exist
    if (L == nullptr) return nullptr;


    d_List* Backward = new d_List;

    // Empty List
    if (L->pHead == nullptr) return Backward;

    // Adding Node Backwardly
    d_NODE* tmp = L->pTail;
    while (tmp)
    {
        addTail(Backward,tmp->key);
        tmp = tmp->pPrev;
    }
    return Backward;
}

void removeDuplicate(d_List *&L)
{
    // List doesn't exist || Empty List
    if (L == nullptr || L->pHead == nullptr) return;

    d_NODE* tmp = L->pHead;
    while (tmp->pNext)
    {
        // Delete Repeat Node
        if (tmp->key == tmp->pNext->key)
        {
            d_NODE* del = tmp->pNext;
            // Fix the Link
            tmp->pNext = del->pNext;
            if (del->pNext != nullptr)
                del->pNext->pPrev = tmp;
        }
        // Otherwise, Move to Next Node
        else
            tmp = tmp->pNext;
    }
}

bool removeElement(d_List *&L, int key)
{
    // List doesn't exist || Empty List
    if (L == nullptr || L->pTail == nullptr) return 0;

    // Find the Specific key
    d_NODE* tmp = L->pHead;
    while (tmp->key != key && tmp)
        tmp = tmp->pNext;
    
    // No such Node with Key value was found in the List
    if (tmp == nullptr) return 0;

    // Remove Head
    if (tmp == L->pHead)
        removeHead(L);
    // Remove Tail
    else if (tmp == L->pTail)
        removeTail(L);
    // Remove Normal Node
    else
    {
        d_NODE* del = tmp;
        del->pPrev->pNext = tmp->pNext;
        del->pNext->pPrev = tmp->pPrev;
    }
    
    return 1;
}
/*
// --- Function main to test the above functions ---

int main()
{
    std::cout << "--- Begin running test cases ---" << std::endl;

    // Test case 1: createNode /////////////////////////////////////////////////
    std::cout << "Test createNode: ";
    d_NODE *node1 = createNode(10);
    assert(node1 != nullptr && node1->key == 10 && node1->pNext == nullptr);
    std::cout << "Passed" << std::endl;
    delete node1;

    // Test case 2: createList //////////////////////////////////////////////////
    std::cout << "Test createList: ";
    d_NODE *head2 = createNode(20);
    d_List *list2 = createList(head2);
    assert(list2 != nullptr && list2->pHead == head2 && list2->pTail == head2);
    std::cout << "Passed" << std::endl;
    freeList(list2);

    // Test case 3: addHead //////////////////////////////////////////////////////
    std::cout << "Test addHead: ";
    d_List *list3 = new d_List();
    assert(addHead(list3, 30));
    assert(list3->pHead != nullptr && list3->pHead->key == 30 && list3->pTail->key == 30);
    assert(addHead(list3, 40));
    assert(list3->pHead->key == 40 && list3->pHead->pNext->key == 30 && list3->pTail->key == 30);
    std::cout << "Passed" << std::endl;
    freeList(list3);

    // Test case 4: addTail /////////////////////////////////////////////////////////
    std::cout << "Test addTail: ";
    d_List *list4 = new d_List();
    assert(addTail(list4, 50));
    assert(list4->pHead != nullptr && list4->pHead->key == 50 && list4->pTail->key == 50);
    assert(addTail(list4, 60));
    assert(list4->pHead->key == 50 && list4->pTail->key == 60 && list4->pHead->pNext->key == 60);
    std::cout << "Passed" << std::endl;
    freeList(list4);

    // Test case 5: removeHead //////////////////////////////////////////////////////////////////
    std::cout << "Test removeHead: ";
    int arr1[3] = {70, 80, 90};
    d_List *list5 = createListFromArray(arr1, 3);
    assert(removeHead(list5) && list5->pHead->key == 80);
    assert(removeHead(list5) && list5->pHead->key == 90);
    assert(removeHead(list5) && list5->pHead == nullptr && list5->pTail == nullptr);
    assert(!removeHead(list5)); // Remove from empty list
    std::cout << "Passed" << std::endl;
    freeList(list5);

    // Test case 6: removeTail ///////////////////////////////////////////////////////////////////
    std::cout << "Test removeTail: ";
    int arr2[3] = {100, 110, 120};
    d_List *list6 = createListFromArray(arr2, 3);
    removeTail(list6);
    assert(list6->pTail->key == 110 && list6->pTail->pNext == nullptr);
    removeTail(list6);
    assert(list6->pTail->key == 100 && list6->pTail->pNext == nullptr && list6->pHead == list6->pTail);
    removeTail(list6);
    assert(list6->pHead == nullptr && list6->pTail == nullptr);
    d_List *emptyList6 = new d_List();
    removeTail(emptyList6); // Remove from empty list
    std::cout << "Passed" << std::endl;
    freeList(emptyList6);
    freeList(list6);

    // Test case 7: removeAll /////////////////////////////////////////////////////////////////////
    std::cout << "Test removeAll: ";
    int arr3[3] = {130, 140, 150};
    d_List *list7 = createListFromArray(arr3, 3);
    removeAll(list7);
    assert(list7->pHead == nullptr && list7->pTail == nullptr);
    d_List *emptyList7 = new d_List();
    removeAll(emptyList7); // Remove from empty list
    assert(emptyList7->pHead == nullptr && emptyList7->pTail == nullptr);
    std::cout << "Passed" << std::endl;
    freeList(emptyList7);
    freeList(list7);

    // Test case 8: removeBefore //////////////////////////////////////////////////////////////////////
    std::cout << "Test removeBefore: ";
    int arr4[5] = {160, 170, 180, 190, 200};
    d_List *list8 = createListFromArray(arr4, 5);

    // testcase 1
    removeBefore(list8, 180);
    int expectedArr8[4] = {160, 180, 190, 200};
    d_List *expectedList8 = createListFromArray(expectedArr8, 4);
    assert(areListsEqual(list8, expectedList8));

    // testcase 2
    removeBefore(list8, 200);
    int expectedArr8_2[3] = {160, 180, 200};
    d_List *expectedList8_2 = createListFromArray(expectedArr8_2, 3);
    assert(areListsEqual(list8, expectedList8_2));

    // testcase 3
    removeBefore(list8, 170); // Don't have any element before
    int expectedArr8_2_2[3] = {160, 180, 200};
    d_List *expectedList8_2_2 = createListFromArray(expectedArr8_2_2, 3);
    assert(areListsEqual(list8, expectedList8_2_2));

    // free memory
    freeList(expectedList8);
    freeList(expectedList8_2);
    freeList(expectedList8_2_2);
    freeList(list8);
    std::cout << "Passed" << std::endl;

    // Test case 9: remove after ////////////////////////////////////////////////////////////
    std::cout << "Test removeAfter: ";
    int arr5[4] = {220, 230, 240, 250};
    d_List *list9 = createListFromArray(arr5, 4);
    // testcase 1
    removeAfter(list9, 220);
    int expectedArr9[3] = {220, 240, 250};
    d_List *expectedList9 = createListFromArray(expectedArr9, 3);
    assert(areListsEqual(list9, expectedList9));
    // testcase 2
    removeAfter(list9, 250); // Don't have any element after
    int expectedArr9_2[3] = {220, 240, 250};
    d_List *expectedList9_2 = createListFromArray(expectedArr9_2, 3);
    assert(areListsEqual(list9, expectedList9_2));
    // testcase 3
    removeAfter(list9, 240);
    int expectedArr9_3[2] = {220, 240};
    d_List *expectedList9_3 = createListFromArray(expectedArr9_3, 2);
    assert(areListsEqual(list9, expectedList9_3));
    // testcase 4
    int arr9_single[1] = {260};
    d_List *list9_single = createListFromArray(arr9_single, 1);
    removeAfter(list9_single, 260);
    int expectedArr9_single[1] = {260};
    d_List *expectedList9_single = createListFromArray(expectedArr9_single, 1);
    assert(areListsEqual(list9_single, expectedList9_single));
    // testcase 5
    d_List *emptyList9 = new d_List();
    removeAfter(emptyList9, 270);
    assert(areListsEqual(emptyList9, new d_List()));
    // free memory
    freeList(expectedList9);
    freeList(expectedList9_2);
    freeList(expectedList9_3);
    freeList(expectedList9_single);
    freeList(list9);
    freeList(list9_single);
    freeList(emptyList9);
    std::cout << "Passed" << std::endl;

    // // Test case 10: addPos /////////////////////////////////////////////////////////
    std::cout << "Test addPos: ";
    d_List *list10 = new d_List();
    assert(addPos(list10, 280, 0));
    assert(list10->pHead != nullptr && list10->pHead->key == 280 && list10->pTail->key == 280);
    assert(addPos(list10, 290, 1));
    assert(list10->pHead->key == 280 && list10->pTail->key == 290 && list10->pHead->pNext->key == 290);
    assert(addPos(list10, 300, 1));
    assert(list10->pHead->key == 280 && list10->pTail->key == 290 && list10->pHead->pNext->key == 300);
    assert(list10->pHead->pNext->pNext->key == 290);
    assert(addPos(list10, 310, 3));
    assert(list10->pHead->key == 280 && list10->pTail->key == 310 && list10->pHead->pNext->key == 300);
    assert(list10->pHead->pNext->pNext->key == 290 && list10->pHead->pNext->pNext->pNext->key == 310);
    assert(!addPos(list10, 320, 5));  // Positions out of range
    assert(!addPos(list10, 330, -1)); // Negative position
    // free memory
    freeList(list10);
    std::cout << "Passed" << std::endl;

    // Test case 11: RemovePos /////////////////////////////////////////////////////////
    std::cout << "Test RemovePos: ";
    int arr11[5] = {340, 350, 360, 370, 380};
    d_List *list11 = createListFromArray(arr11, 5);
    assert(list11->pHead->key == 340 && list11->pTail->key == 380);
    // testcase 1
    removePos(list11, 340, 0);
    assert(list11->pHead->key == 350 && list11->pTail->key == 380);
    assert(list11->pHead->pNext->key == 360 && list11->pHead->pNext->pNext->key == 370 && list11->pHead->pNext->pNext->pNext->key == 380);
    assert(list11->pHead->pNext->pNext->pNext->pNext == nullptr);
    // testcase 2
    removePos(list11, 370, 2);
    assert(list11->pHead->key == 350 && list11->pTail->key == 380);
    assert(list11->pHead->pNext->key == 360 && list11->pHead->pNext->pNext->key == 380);
    assert(list11->pHead->pNext->pNext->pNext == nullptr);
    // testcase 3
    removePos(list11, 350, 5); // Positions out of range
    assert(list11->pHead->key == 350 && list11->pTail->key == 380);
    assert(list11->pHead->pNext->key == 360 && list11->pHead->pNext->pNext->key == 380);
    assert(list11->pHead->pNext->pNext->pNext == nullptr);
    // free memory
    freeList(list11);
    std::cout << "Passed" << std::endl;

    // Test case 12: addBefore /////////////////////////////////////////////////////////
    std::cout << "Test addBefore: ";
    int arr12[4] = {390, 400, 410, 420};
    d_List *list12 = createListFromArray(arr12, 4);
    assert(list12->pHead->key == 390 && list12->pTail->key == 420);
    // testcase 1
    addBefore(list12, 380, 400);
    int arr12_1[5] = {390, 380, 400, 410, 420};
    d_List *expectedList12_1 = createListFromArray(arr12_1, 5);
    assert(areListsEqual(list12, expectedList12_1));
    // testcase 2
    addBefore(list12, 370, 390);
    int arr12_2[6] = {370, 390, 380, 400, 410, 420};
    d_List *expectedList12_2 = createListFromArray(arr12_2, 6);
    assert(areListsEqual(list12, expectedList12_2));
    // testcase 3
    addBefore(list12, 360, 350); // Don't have any element before
    int arr12_3[6] = {370, 390, 380, 400, 410, 420};
    d_List *expectedList12_3 = createListFromArray(arr12_3, 6);
    assert(areListsEqual(list12, expectedList12_3));
    // free memory
    freeList(list12);
    freeList(expectedList12_1);
    freeList(expectedList12_2);
    freeList(expectedList12_3);
    std::cout << "Passed" << std::endl;

    // Test case 13: addAfter /////////////////////////////////////////////////////////
    std::cout << "Test addAfter: ";
    int arr13[4] = {430, 440, 450, 460};
    d_List *list13 = createListFromArray(arr13, 4);
    assert(list13->pHead->key == 430 && list13->pTail->key == 460);
    // testcase 1
    addAfter(list13, 470, 440);
    int arr13_1[5] = {430, 440, 470, 450, 460};
    d_List *expectedList13_1 = createListFromArray(arr13_1, 5);
    assert(areListsEqual(list13, expectedList13_1));
    // testcase 2
    addAfter(list13, 480, 460);
    int arr13_2[6] = {430, 440, 470, 450, 460, 480};
    d_List *expectedList13_2 = createListFromArray(arr13_2, 6);
    assert(areListsEqual(list13, expectedList13_2));
    // testcase 3
    addAfter(list13, 490, 200); // Don't have any element after
    int arr13_3[6] = {430, 440, 470, 450, 460, 480};
    d_List *expectedList13_3 = createListFromArray(arr13_3, 6);
    assert(areListsEqual(list13, expectedList13_3));
    // free memory
    freeList(expectedList13_1);
    freeList(expectedList13_2);
    freeList(expectedList13_3);
    freeList(list13);
    std::cout << "Passed" << std::endl;

    // Test case 14: printList /////////////////////////////////////////////////////////
    std::cout << "Test printList: "; // Don't need to assert anything
    std::cout << "Passed" << std::endl;

    // Test case 15: countElements /////////////////////////////////////////////////////////
    std::cout << "Test countElements: ";
    // Test case 1
    int arr15[5] = {500, 510, 520, 530, 540};
    d_List *list15 = createListFromArray(arr15, 5);
    assert(countElements(list15) == 5);
    // Test case 2
    int arr15_2[3] = {550, 560, 570};
    d_List *list15_2 = createListFromArray(arr15_2, 3);
    assert(countElements(list15_2) == 3);
    // Test case 3
    int arr15_3[1] = {580};
    d_List *list15_3 = createListFromArray(arr15_3, 1);
    assert(countElements(list15_3) == 1);
    // Test case 4
    d_List *emptyList15 = new d_List();
    assert(countElements(emptyList15) == 0);
    // free memory
    freeList(list15);
    freeList(list15_2);
    freeList(list15_3);
    freeList(emptyList15);
    std::cout << "Passed" << std::endl;

    // Test case 16: reverseList /////////////////////////////////////////////////////////
    std::cout << "Test reverseList: ";
    // Test case 1
    int arr16[5] = {590, 600, 610, 620, 630};
    d_List *list16 = createListFromArray(arr16, 5);
    d_List *reversedList16 = reverseList(list16);
    int expectedArr16[5] = {630, 620, 610, 600, 590};
    d_List *expectedList16 = createListFromArray(expectedArr16, 5);
    assert(areListsEqual(reversedList16, expectedList16));
    // Test case 2
    int arr16_2[3] = {640, 650, 660};
    d_List *list16_2 = createListFromArray(arr16_2, 3);
    d_List *reversedList16_2 = reverseList(list16_2);
    int expectedArr16_2[3] = {660, 650, 640};
    d_List *expectedList16_2 = createListFromArray(expectedArr16_2, 3);
    assert(areListsEqual(reversedList16_2, expectedList16_2));
    // Test case 3
    int arr16_3[1] = {670};
    d_List *list16_3 = createListFromArray(arr16_3, 1);
    d_List *reversedList16_3 = reverseList(list16_3);
    int expectedArr16_3[1] = {670};
    d_List *expectedList16_3 = createListFromArray(expectedArr16_3, 1);
    assert(areListsEqual(reversedList16_3, expectedList16_3));
    // Test case 4
    d_List *emptyList16 = new d_List();
    d_List *reversedList16_4 = reverseList(emptyList16);
    assert(reversedList16_4->pHead == nullptr && reversedList16_4->pTail == nullptr);
    // free memory
    freeList(expectedList16);
    freeList(expectedList16_2);
    freeList(expectedList16_3);
    freeList(reversedList16);
    freeList(reversedList16_2);
    freeList(reversedList16_3);
    freeList(reversedList16_4);
    freeList(list16);
    freeList(list16_2);
    freeList(list16_3);
    freeList(emptyList16);
    std::cout << "Passed" << std::endl;

    // Test case 17: removeDuplicate /////////////////////////////////////////////////////////
    std::cout << "Test removeDuplicate: ";
    // Test case 1
    int arr17[6] = {680, 690, 690, 700, 710, 710};
    d_List *list17 = createListFromArray(arr17, 6);
    removeDuplicate(list17);
    int expectedArr17[4] = {680, 690, 700, 710};
    d_List *expectedList17 = createListFromArray(expectedArr17, 4);
    assert(areListsEqual(list17, expectedList17));
    // Test case 2
    int arr17_2[5] = {720, 730, 740, 740, 740};
    d_List *list17_2 = createListFromArray(arr17_2, 5);
    removeDuplicate(list17_2);
    int expectedArr17_2[3] = {720, 730, 740};
    d_List *expectedList17_2 = createListFromArray(expectedArr17_2, 3);
    assert(areListsEqual(list17_2, expectedList17_2));
    // Test case 3
    int arr17_3[4] = {750, 760, 760, 770};
    d_List *list17_3 = createListFromArray(arr17_3, 4);
    removeDuplicate(list17_3);
    int expectedArr17_3[3] = {750, 760, 770};
    d_List *expectedList17_3 = createListFromArray(expectedArr17_3, 3);
    assert(areListsEqual(list17_3, expectedList17_3));
    // Test case 4
    int arr17_4[2] = {780, 780};
    d_List *list17_4 = createListFromArray(arr17_4, 2);
    removeDuplicate(list17_4);
    int expectedArr17_4[1] = {780};
    d_List *expectedList17_4 = createListFromArray(expectedArr17_4, 1);
    assert(areListsEqual(list17_4, expectedList17_4));
    // Test case 5
    int arr17_5[1] = {790};
    d_List *list17_5 = createListFromArray(arr17_5, 1);
    removeDuplicate(list17_5);
    int expectedArr17_5[1] = {790};
    d_List *expectedList17_5 = createListFromArray(expectedArr17_5, 1);
    assert(areListsEqual(list17_5, expectedList17_5));
    // Test case 6
    d_List *emptyList17 = new d_List();
    removeDuplicate(emptyList17);
    assert(emptyList17->pHead == nullptr && emptyList17->pTail == nullptr);
    // free memory
    freeList(expectedList17);
    freeList(expectedList17_2);
    freeList(expectedList17_3);
    freeList(expectedList17_4);
    freeList(expectedList17_5);
    freeList(list17);
    freeList(list17_2);
    freeList(list17_3);
    freeList(list17_4);
    freeList(list17_5);
    freeList(emptyList17);
    std::cout << "Passed" << std::endl;

    // Test case 18: removeElement /////////////////////////////////////////////////////////
    std::cout << "Test removeElement: ";
    // Test case 1
    int arr18[5] = {800, 810, 820, 830, 840};
    d_List *list18 = createListFromArray(arr18, 5);
    assert(removeElement(list18, 820));
    int expectedArr18[4] = {800, 810, 830, 840};
    d_List *expectedList18 = createListFromArray(expectedArr18, 4);
    assert(areListsEqual(list18, expectedList18));
    // Test case 2
    int arr18_2[3] = {850, 860, 870};
    d_List *list18_2 = createListFromArray(arr18_2, 3);
    assert(removeElement(list18_2, 850));
    int expectedArr18_2[2] = {860, 870};
    d_List *expectedList18_2 = createListFromArray(expectedArr18_2, 2);
    assert(areListsEqual(list18_2, expectedList18_2));
    // Test case 3
    int arr18_3[4] = {880, 890, 900, 910};
    d_List *list18_3 = createListFromArray(arr18_3, 4);
    assert(removeElement(list18_3, 910));
    int expectedArr18_3[3] = {880, 890, 900};
    d_List *expectedList18_3 = createListFromArray(expectedArr18_3, 3);
    assert(areListsEqual(list18_3, expectedList18_3));
    // Test case 4
    int arr18_4[2] = {920, 930};
    d_List *list18_4 = createListFromArray(arr18_4, 2);
    assert(removeElement(list18_4, 920));
    int expectedArr18_4[1] = {930};
    d_List *expectedList18_4 = createListFromArray(expectedArr18_4, 1);
    assert(areListsEqual(list18_4, expectedList18_4));
    // Test case 5
    int arr18_5[1] = {940};
    d_List *list18_5 = createListFromArray(arr18_5, 1);
    assert(removeElement(list18_5, 940));
    // Test case 6
    d_List *emptyList18 = new d_List();
    assert(!removeElement(emptyList18, 950)); // Remove from empty list
    assert(emptyList18->pHead == nullptr && emptyList18->pTail == nullptr);
    // free memory
    freeList(expectedList18);
    freeList(expectedList18_2);
    freeList(expectedList18_3);
    freeList(expectedList18_4);
    freeList(list18);
    freeList(list18_2);
    freeList(list18_3);
    freeList(list18_4);
    freeList(list18_5);
    freeList(emptyList18);
    std::cout << "Passed" << std::endl;
    std::cout << "--- End running test cases ---" << std::endl;
    return 0;
}
*/#include <iostream>
#include <cassert>
struct NODE
{
    int key;
    NODE *p_next;
};

struct List
{
    NODE *p_head;
    NODE *p_tail;
    List(NODE *head = nullptr, NODE *tail = nullptr) : p_head(head), p_tail(tail) {}
};

// --- Define function prototypes ---
NODE *createNode(int data);
List *createList(NODE *p_node);
bool addHead(List *&L, int data);
bool addTail(List *&L, int data);
bool removeHead(List *&L);
void removeTail(List *&L);
void removeAll(List *&L);
void removeBefore(List *&L, int val);
void removeAfter(List *&L, int val);
bool addPos(List *&L, int data, int pos);
void removePos(List *&L, int data, int pos);
bool addBefore(List *&L, int data, int val);
bool addAfter(List *&L, int data, int val);
void printList(List *L);
int countElements(List *L);
List *reverseList(List *L);
void removeDuplicate(List *&L);
bool removeElement(List *&L, int key);

// function to create a list from an array
List *createListFromArray(int arr[], int n)
{
    List *newList = new List();
    newList->p_head = nullptr;
    newList->p_tail = nullptr;
    for (int i = 0; i < n; ++i)
    {
        addTail(newList, arr[i]);
    }
    return newList;
}

// function to compare two lists
bool areListsEqual(List *list1, List *list2)
{
    NODE *current1 = list1 ? list1->p_head : nullptr;
    NODE *current2 = list2 ? list2->p_head : nullptr;
    while (current1 && current2)
    {
        if (current1->key != current2->key)
        {
            return false;
        }
        current1 = current1->p_next;
        current2 = current2->p_next;
    }
    return (current1 == nullptr && current2 == nullptr);
}

// function to free the memory of a list
void freeList(List *L)
{
    NODE *current = L->p_head;
    while (current)
    {
        NODE *next = current->p_next;
        delete current;
        current = next;
    }
    delete L;
}

NODE *createNode(int data)
{
    // Allocate a new Node
    NODE* newNode = new NODE;

    newNode->key = data;
    newNode->p_next = nullptr;

    // Out of Memory for alloction
    if (newNode == nullptr)
        return nullptr;
    return newNode; // Placeholder return statement
}

List *createList(NODE *p_node)
{
    // Allocate a new List
    List* list = new List;
    list->p_head = list->p_tail = p_node;

    // Out of memory for allocating
    if (list == nullptr)
        return nullptr;

    return list; // Placeholder return statement
}

bool addHead(List *&L, int data)
{
    NODE* add = createNode(data);

    // There is no list
    if (L == nullptr)
    {
        delete add;
        return 0;
    }

    // Empty List Cases
    if (L->p_head == nullptr)
        L->p_head = L->p_tail = add;
    else    // Normal cases
    {
        add->p_next = L->p_head;
        L->p_head = add;
    }

    return 1;
}

bool addTail(List *&L, int data) // this function is kept for createListfromArray function
{
    // No such List exsit
    if (L == nullptr)
        return 0;


    NODE *newNode = createNode(data);
    // Adding tail to the empty List
    if (L->p_head == nullptr)
    {
        L->p_head = newNode;
        L->p_tail = newNode;
    }
    else
    {
        L->p_tail->p_next = newNode;
        L->p_tail = newNode;
    }
    return 1;
}

bool removeHead(List *&L)
{
    // Empty List cases
    if (L == nullptr || L->p_head == nullptr)
        return 0;
    // Delete the List has 1 Node
    if (L->p_head->p_next == nullptr)
    {
        delete L->p_head;
        L->p_head = L->p_tail = nullptr;
    }
    else // Normal Cases
    {
        NODE* del = L->p_head;
        L->p_head = del->p_next;
        delete del;
    }

    return 1;
}

void removeTail(List *&L)
{
    // Empty Cases
    if (L == nullptr || L->p_head == nullptr)
        return;
    // Remove from List has 1 Node
    if (L->p_head->p_next == nullptr)
    {
        delete L->p_head;
        L->p_head = L->p_tail = nullptr;
    }
    else        // Normal case
    {
        // Approching the Node next to the tail Node
        NODE* tmp = L->p_head;
        while (tmp->p_next != L->p_tail)
        {
            tmp = tmp->p_next;
        }

        // Remove the tail node, Choose the new Tail Node
        NODE* del = tmp->p_next;
        tmp->p_next = nullptr;
        L->p_tail = tmp;
        delete del;
    }
    return;
}

void removeAll(List *&L)
{
    // Remove Node from empty List
    if (L == nullptr || L->p_head == nullptr)
        return;

    // Delete all the Node in a List but tailNode
    NODE* tmp = L->p_head;
    while (tmp->p_next)
    {
        NODE* del = tmp;
        tmp = tmp->p_next;
        delete del;
    }

    // Delete the Tail Node, return an Empty List
    delete tmp;
    L->p_head = L->p_tail = nullptr;
    return;
}

// Remove a node before a given value in the list if it exists, otherwise do nothing
void removeBefore(List *&L, int val)
{
    // Remove from an emptyList || 1 Node List
    if (L == nullptr || L->p_head == nullptr || L->p_head->p_next == nullptr)
        return;

    NODE* tmp = L->p_head;
    while (tmp->p_next->p_next && tmp->p_next->p_next->key != val)
        tmp = tmp->p_next;

    // No such Node was found to delete
    if (tmp->p_next->p_next == nullptr)
        return;
    
    // Remove the Node infornt of the specific value Node
    NODE* del = tmp->p_next;
    tmp->p_next = del->p_next;
    delete del;

}

void removeAfter(List *&L, int val)
{
    // Remove from an emptyList || 1 Node List
    if (L == nullptr || L->p_head == nullptr || L->p_head->p_next == nullptr)
        return;

    // Moving to the Node in front of the delete Node
    NODE* tmp = L->p_head;
    while (tmp->p_next && tmp->key != val)
    {
        tmp = tmp->p_next;
    }
    if (tmp == L->p_tail) return;   // Cannot Find the Node to remove


    NODE* del = tmp->p_next;
    if (del == L->p_tail)      // Remove the tail Node Case
        removeTail(L);
    else                        // Normal cases
    {
        tmp->p_next = del->p_next;
        delete del;
    }

    return;
}

bool addPos(List*& L, int data, int pos)
{
    // Add to an empty List
    if (L == nullptr)
        return 0;

    if (L->p_head == nullptr && pos == 0)
    {
        addHead(L, data);
        return 1;
    }
    else if (L->p_head == nullptr)
        return 0;

    // Move to the correct position
    NODE* tmp = L->p_head;
    while (--pos != 0 && tmp->p_next)
    {
        tmp = tmp->p_next;
    }

    // Out of range
    if (pos != 0) return 0;

    // Adding to the Tail
    if (tmp == L->p_tail)
        addTail(L, data);
    // Adding new Node behind the tmp Node
    else
    {
        NODE* add = createNode(data);
        add->p_next = tmp->p_next;
        tmp->p_next = add;

    }
    return 1;
}

void removePos(List *&L, int data, int pos)
{
    // Remove from an empty List || invalid cases
    if (L == nullptr || L->p_head == nullptr || pos < 0)
        return;

    // Remove Head case
    if (pos == 0 && L->p_head->key == data)
    {
        removeHead(L);
        return;
    }

    NODE* tmp = L->p_head;
    while (--pos != 0 && tmp->p_next)
    {
        tmp = tmp->p_next;
    }

    // No such node with value at the position
    if (tmp->p_next == nullptr || tmp->p_next->key != data || pos != 0) return;

    NODE* del = tmp->p_next;
    tmp->p_next = del->p_next;
    delete del;
    return;
}

// Insert an integer before a value of a given List:
bool addBefore(List *&L, int data, int val)
{
    // Cannot Isert ot an empty List
    if (L == nullptr || L->p_head == nullptr)
        return 0;

    // Add head
    if (L->p_head->key == val)
    {
        addHead(L, data);
        return 1;
    }
    
    // Moving to the Node with Specific key
    NODE* tmp = L->p_head;
    while (tmp->p_next && tmp->p_next->key != val)
        tmp = tmp->p_next;

    // Cannot Find the Spicefic Key
    if (tmp->p_next == nullptr) return 0;

    NODE* add = createNode(data);
    add->p_next = tmp->p_next;
    tmp->p_next = add;
    return 1;
}

bool addAfter(List *&L, int data, int val)
{
    // Cannot Isert ot an empty List
    if (L == nullptr || L->p_head == nullptr)
        return 0;

    // Move to the Specific Key Node
    NODE* tmp = L->p_head;
    while (tmp->p_next && tmp->key != val)
        tmp = tmp->p_next;


    // Cannot find Specific key
    if (tmp->p_next == nullptr && tmp->key != val)
        return 0;
    // Add to the tail cases
    if (tmp->p_next == nullptr && tmp->key == val)
        addTail(L, data);
    // Add between Node
    else
    {
        NODE* add = createNode(data);
        add->p_next = tmp->p_next;
        tmp->p_next = add;
    }
    return 1;
}

void printList(List *L)
{
    // Display an Empty List
    if (L == nullptr || L->p_head == nullptr)
        return;

    // Display all Node in the List
    NODE* tmp = L->p_head;
    while (tmp)
    {
        std::cout << tmp->key << "  --->  ";
        tmp = tmp->p_next;
    }
    std::cout << "NULL\n";

    return;
}

int countElements(List *L)
{
    // Counting an empty List
    if (L == nullptr || L->p_head == nullptr)
        return 0;

    // Counting each Node in the List
    int count = 0;
    NODE* tmp = L->p_head;
    while (tmp && ++count)
        tmp = tmp->p_next;

    return count;
}

List *reverseList(List *L)
{
    // Create an Empty List
    List* BackWard = new List;
    BackWard->p_head = BackWard->p_tail = nullptr;

    // Empty Node Case
    if (L == nullptr || L->p_head == nullptr)
        return BackWard;
    

    // Every time move to a New Node, add a same key value to the head of the result list
    NODE* tmp = L->p_head;
    while (tmp)
    {
        addHead(BackWard, tmp->key);
        tmp = tmp->p_next;
    }

    return BackWard;
}

void removeDuplicate(List *&L)
{
    // Remove from an Empty List
    if (L == nullptr || L->p_head == nullptr)
        return;

    // Removing Pepeat Node
    NODE* tmp = L->p_head;
    // Searching in the List
    while (tmp->p_next)
    {
        // Found an Repeat Node, delete it
        if (tmp->key == tmp->p_next->key)
        {
            NODE* del = tmp->p_next;
            tmp->p_next = del->p_next;
            delete del;
        }
        // Otherwise, Move to the next Node
        else
            tmp = tmp->p_next;
    }
}

bool removeElement(List *&L, int key)
{
    // Empty List
    if (L == nullptr || L->p_head == nullptr)
        return 0;

    // key Node is the Head
    if (L->p_head->key == key)
    {
        removeHead(L);
        return 1;
    }

    // Find the key in the List
    NODE* tmp = L->p_head;
    while (tmp->p_next->p_next &&  tmp->p_next->key != key)
    {
        tmp = tmp->p_next;
    }
    // No such Key was found
    if (tmp->p_next == L->p_tail && tmp->p_next->key != key) return 0;
    
    // Delete the Node specific Key
    NODE* del = tmp->p_next;
    tmp->p_next = del->p_next;
    delete del;
    return 1;
}

// --- Function main to test the above functions ---

int main()
{
    std::cout << "--- Begin running test cases ---" << std::endl;

    // Test case 1: createNode /////////////////////////////////////////////////
    std::cout << "Test createNode: ";
    NODE *node1 = createNode(10);
    assert(node1 != nullptr && node1->key == 10 && node1->p_next == nullptr);
    std::cout << "Passed" << std::endl;
    delete node1;

    // Test case 2: createList //////////////////////////////////////////////////
    std::cout << "Test createList: ";
    NODE *head2 = createNode(20);
    List *list2 = createList(head2);
    assert(list2 != nullptr && list2->p_head == head2 && list2->p_tail == head2);
    std::cout << "Passed" << std::endl;
    freeList(list2);

    // Test case 3: addHead //////////////////////////////////////////////////////
    std::cout << "Test addHead: ";
    List *list3 = new List();
    assert(addHead(list3, 30));
    assert(list3->p_head != nullptr && list3->p_head->key == 30 && list3->p_tail->key == 30);
    assert(addHead(list3, 40));
    assert(list3->p_head->key == 40 && list3->p_head->p_next->key == 30 && list3->p_tail->key == 30);
    std::cout << "Passed" << std::endl;
    freeList(list3);

    // Test case 4: addTail /////////////////////////////////////////////////////////
    std::cout << "Test addTail: ";
    List *list4 = new List();
    assert(addTail(list4, 50));
    assert(list4->p_head != nullptr && list4->p_head->key == 50 && list4->p_tail->key == 50);
    assert(addTail(list4, 60));
    assert(list4->p_head->key == 50 && list4->p_tail->key == 60 && list4->p_head->p_next->key == 60);
    std::cout << "Passed" << std::endl;
    freeList(list4);

    // Test case 5: removeHead //////////////////////////////////////////////////////////////////
    std::cout << "Test removeHead: ";
    int arr1[3] = {70, 80, 90};
    List *list5 = createListFromArray(arr1, 3);
    assert(removeHead(list5) && list5->p_head->key == 80);
    assert(removeHead(list5) && list5->p_head->key == 90);
    assert(removeHead(list5) && list5->p_head == nullptr && list5->p_tail == nullptr);
    assert(!removeHead(list5)); // Remove from empty list
    std::cout << "Passed" << std::endl;
    freeList(list5);

    // Test case 6: removeTail ///////////////////////////////////////////////////////////////////
    std::cout << "Test removeTail: ";
    int arr2[3] = {100, 110, 120};
    List *list6 = createListFromArray(arr2, 3);
    removeTail(list6);
    assert(list6->p_tail->key == 110 && list6->p_tail->p_next == nullptr);
    removeTail(list6);
    assert(list6->p_tail->key == 100 && list6->p_tail->p_next == nullptr && list6->p_head == list6->p_tail);
    removeTail(list6);
    assert(list6->p_head == nullptr && list6->p_tail == nullptr);
    List *emptyList6 = new List();
    removeTail(emptyList6); // Remove from empty list
    std::cout << "Passed" << std::endl;
    freeList(emptyList6);
    freeList(list6);

    // Test case 7: removeAll /////////////////////////////////////////////////////////////////////
    std::cout << "Test removeAll: ";
    int arr3[3] = {130, 140, 150};
    List *list7 = createListFromArray(arr3, 3);
    removeAll(list7);
    assert(list7->p_head == nullptr && list7->p_tail == nullptr);
    List *emptyList7 = new List();
    removeAll(emptyList7); // Remove from empty list
    assert(emptyList7->p_head == nullptr && emptyList7->p_tail == nullptr);
    std::cout << "Passed" << std::endl;
    freeList(emptyList7);
    freeList(list7);

    // Test case 8: removeBefore //////////////////////////////////////////////////////////////////////
    std::cout << "Test removeBefore: ";
    int arr4[5] = {160, 170, 180, 190, 200};
    List *list8 = createListFromArray(arr4, 5);

    // testcase 1
    removeBefore(list8, 180);
    int expectedArr8[4] = {160, 180, 190, 200};
    List *expectedList8 = createListFromArray(expectedArr8, 4);
    assert(areListsEqual(list8, expectedList8));

    // testcase 2
    removeBefore(list8, 200);
    int expectedArr8_2[3] = {160, 180, 200};
    List *expectedList8_2 = createListFromArray(expectedArr8_2, 3);
    assert(areListsEqual(list8, expectedList8_2));

    // testcase 3
    removeBefore(list8, 170); // Don't have any element before
    int expectedArr8_2_2[3] = {160, 180, 200};
    List *expectedList8_2_2 = createListFromArray(expectedArr8_2_2, 3);
    assert(areListsEqual(list8, expectedList8_2_2));

    // free memory
    freeList(expectedList8);
    freeList(expectedList8_2);
    freeList(expectedList8_2_2);
    freeList(list8);
    std::cout << "Passed" << std::endl;

    // Test case 9: remove after ////////////////////////////////////////////////////////////
    std::cout << "Test removeAfter: ";
    int arr5[4] = {220, 230, 240, 250};
    List *list9 = createListFromArray(arr5, 4);
    // testcase 1
    removeAfter(list9, 220);
    int expectedArr9[3] = {220, 240, 250};
    List *expectedList9 = createListFromArray(expectedArr9, 3);
    assert(areListsEqual(list9, expectedList9));
    // testcase 2
    removeAfter(list9, 250); // Don't have any element after
    int expectedArr9_2[3] = {220, 240, 250};
    List *expectedList9_2 = createListFromArray(expectedArr9_2, 3);
    assert(areListsEqual(list9, expectedList9_2));
    // testcase 3
    removeAfter(list9, 240);
    int expectedArr9_3[2] = {220, 240};
    List *expectedList9_3 = createListFromArray(expectedArr9_3, 2);
    assert(areListsEqual(list9, expectedList9_3));
    // testcase 4
    int arr9_single[1] = {260};
    List *list9_single = createListFromArray(arr9_single, 1);
    removeAfter(list9_single, 260);
    int expectedArr9_single[1] = {260};
    List *expectedList9_single = createListFromArray(expectedArr9_single, 1);
    assert(areListsEqual(list9_single, expectedList9_single));
    // testcase 5
    List *emptyList9 = new List();
    removeAfter(emptyList9, 270);
    assert(areListsEqual(emptyList9, new List()));
    // free memory
    freeList(expectedList9);
    freeList(expectedList9_2);
    freeList(expectedList9_3);
    freeList(expectedList9_single);
    freeList(list9);
    freeList(list9_single);
    freeList(emptyList9);
    std::cout << "Passed" << std::endl;

    // // Test case 10: addPos /////////////////////////////////////////////////////////
    std::cout << "Test addPos: ";
    List *list10 = new List();
    assert(addPos(list10, 280, 0));
    assert(list10->p_head != nullptr && list10->p_head->key == 280 && list10->p_tail->key == 280);
    assert(addPos(list10, 290, 1));
    assert(list10->p_head->key == 280 && list10->p_tail->key == 290 && list10->p_head->p_next->key == 290);
    assert(addPos(list10, 300, 1));
    assert(list10->p_head->key == 280 && list10->p_tail->key == 290 && list10->p_head->p_next->key == 300);
    assert(list10->p_head->p_next->p_next->key == 290);
    assert(addPos(list10, 310, 3));
    assert(list10->p_head->key == 280 && list10->p_tail->key == 310 && list10->p_head->p_next->key == 300);
    assert(list10->p_head->p_next->p_next->key == 290 && list10->p_head->p_next->p_next->p_next->key == 310);
    assert(!addPos(list10, 320, 5));  // Positions out of range
    assert(!addPos(list10, 330, -1)); // Negative position
    // free memory
    freeList(list10);
    std::cout << "Passed" << std::endl;

    // Test case 11: RemovePos /////////////////////////////////////////////////////////
    std::cout << "Test RemovePos: ";
    int arr11[5] = {340, 350, 360, 370, 380};
    List *list11 = createListFromArray(arr11, 5);
    assert(list11->p_head->key == 340 && list11->p_tail->key == 380);
    // testcase 1
    removePos(list11, 340, 0);
    assert(list11->p_head->key == 350 && list11->p_tail->key == 380);
    assert(list11->p_head->p_next->key == 360 && list11->p_head->p_next->p_next->key == 370 && list11->p_head->p_next->p_next->p_next->key == 380);
    assert(list11->p_head->p_next->p_next->p_next->p_next == nullptr);
    // testcase 2
    removePos(list11, 370, 2);
    assert(list11->p_head->key == 350 && list11->p_tail->key == 380);
    assert(list11->p_head->p_next->key == 360 && list11->p_head->p_next->p_next->key == 380);
    assert(list11->p_head->p_next->p_next->p_next == nullptr);
    // testcase 3
    removePos(list11, 350, 5); // Positions out of range
    assert(list11->p_head->key == 350 && list11->p_tail->key == 380);
    assert(list11->p_head->p_next->key == 360 && list11->p_head->p_next->p_next->key == 380);
    assert(list11->p_head->p_next->p_next->p_next == nullptr);
    // free memory
    freeList(list11);
    std::cout << "Passed" << std::endl;

    // Test case 12: addBefore /////////////////////////////////////////////////////////
    std::cout << "Test addBefore: ";
    int arr12[4] = {390, 400, 410, 420};
    List *list12 = createListFromArray(arr12, 4);
    assert(list12->p_head->key == 390 && list12->p_tail->key == 420);
    // testcase 1
    addBefore(list12, 380, 400);
    int arr12_1[5] = {390, 380, 400, 410, 420};
    List *expectedList12_1 = createListFromArray(arr12_1, 5);
    assert(areListsEqual(list12, expectedList12_1));
    // testcase 2
    addBefore(list12, 370, 390);
    int arr12_2[6] = {370, 390, 380, 400, 410, 420};
    List *expectedList12_2 = createListFromArray(arr12_2, 6);
    assert(areListsEqual(list12, expectedList12_2));
    // testcase 3
    addBefore(list12, 360, 350); // Don't have any element before
    int arr12_3[6] = {370, 390, 380, 400, 410, 420};
    List *expectedList12_3 = createListFromArray(arr12_3, 6);
    assert(areListsEqual(list12, expectedList12_3));
    // free memory
    freeList(list12);
    freeList(expectedList12_1);
    freeList(expectedList12_2);
    freeList(expectedList12_3);
    std::cout << "Passed" << std::endl;

    // Test case 13: addAfter /////////////////////////////////////////////////////////
    std::cout << "Test addAfter: ";
    int arr13[4] = {430, 440, 450, 460};
    List *list13 = createListFromArray(arr13, 4);
    assert(list13->p_head->key == 430 && list13->p_tail->key == 460);
    // testcase 1
    addAfter(list13, 470, 440);
    int arr13_1[5] = {430, 440, 470, 450, 460};
    List *expectedList13_1 = createListFromArray(arr13_1, 5);
    assert(areListsEqual(list13, expectedList13_1));
    // testcase 2
    addAfter(list13, 480, 460);
    int arr13_2[6] = {430, 440, 470, 450, 460, 480};
    List *expectedList13_2 = createListFromArray(arr13_2, 6);
    assert(areListsEqual(list13, expectedList13_2));
    // testcase 3
    addAfter(list13, 490, 200); // Don't have any element after
    int arr13_3[6] = {430, 440, 470, 450, 460, 480};
    List *expectedList13_3 = createListFromArray(arr13_3, 6);
    assert(areListsEqual(list13, expectedList13_3));
    // free memory
    freeList(expectedList13_1);
    freeList(expectedList13_2);
    freeList(expectedList13_3);
    freeList(list13);
    std::cout << "Passed" << std::endl;

    // Test case 14: printList /////////////////////////////////////////////////////////
    std::cout << "Test printList: "; // Don't need to assert anything
    std::cout << "Passed" << std::endl;

    // Test case 15: countElements /////////////////////////////////////////////////////////
    std::cout << "Test countElements: ";
    // Test case 1
    int arr15[5] = {500, 510, 520, 530, 540};
    List *list15 = createListFromArray(arr15, 5);
    assert(countElements(list15) == 5);
    // Test case 2
    int arr15_2[3] = {550, 560, 570};
    List *list15_2 = createListFromArray(arr15_2, 3);
    assert(countElements(list15_2) == 3);
    // Test case 3
    int arr15_3[1] = {580};
    List *list15_3 = createListFromArray(arr15_3, 1);
    assert(countElements(list15_3) == 1);
    // Test case 4
    List *emptyList15 = new List();
    assert(countElements(emptyList15) == 0);
    // free memory
    freeList(list15);
    freeList(list15_2);
    freeList(list15_3);
    freeList(emptyList15);
    std::cout << "Passed" << std::endl;

    // Test case 16: reverseList /////////////////////////////////////////////////////////
    std::cout << "Test reverseList: ";
    // Test case 1
    int arr16[5] = {590, 600, 610, 620, 630};
    List *list16 = createListFromArray(arr16, 5);
    List *reversedList16 = reverseList(list16);
    int expectedArr16[5] = {630, 620, 610, 600, 590};
    List *expectedList16 = createListFromArray(expectedArr16, 5);
    assert(areListsEqual(reversedList16, expectedList16));
    // Test case 2
    int arr16_2[3] = {640, 650, 660};
    List *list16_2 = createListFromArray(arr16_2, 3);
    List *reversedList16_2 = reverseList(list16_2);
    int expectedArr16_2[3] = {660, 650, 640};
    List *expectedList16_2 = createListFromArray(expectedArr16_2, 3);
    assert(areListsEqual(reversedList16_2, expectedList16_2));
    // Test case 3
    int arr16_3[1] = {670};
    List *list16_3 = createListFromArray(arr16_3, 1);
    List *reversedList16_3 = reverseList(list16_3);
    int expectedArr16_3[1] = {670};
    List *expectedList16_3 = createListFromArray(expectedArr16_3, 1);
    assert(areListsEqual(reversedList16_3, expectedList16_3));
    // Test case 4
    List *emptyList16 = new List();
    List *reversedList16_4 = reverseList(emptyList16);
    assert(reversedList16_4->p_head == nullptr && reversedList16_4->p_tail == nullptr);
    // free memory
    freeList(expectedList16);
    freeList(expectedList16_2);
    freeList(expectedList16_3);
    freeList(reversedList16);
    freeList(reversedList16_2);
    freeList(reversedList16_3);
    freeList(reversedList16_4);
    freeList(list16);
    freeList(list16_2);
    freeList(list16_3);
    freeList(emptyList16);
    std::cout << "Passed" << std::endl;

    // Test case 17: removeDuplicate /////////////////////////////////////////////////////////
    std::cout << "Test removeDuplicate: ";
    // Test case 1
    int arr17[6] = {680, 690, 690, 700, 710, 710};
    List *list17 = createListFromArray(arr17, 6);
    removeDuplicate(list17);
    int expectedArr17[4] = {680, 690, 700, 710};
    List *expectedList17 = createListFromArray(expectedArr17, 4);
    assert(areListsEqual(list17, expectedList17));
    // Test case 2
    int arr17_2[5] = {720, 730, 740, 740, 740};
    List *list17_2 = createListFromArray(arr17_2, 5);
    removeDuplicate(list17_2);
    int expectedArr17_2[3] = {720, 730, 740};
    List *expectedList17_2 = createListFromArray(expectedArr17_2, 3);
    assert(areListsEqual(list17_2, expectedList17_2));
    // Test case 3
    int arr17_3[4] = {750, 760, 760, 770};
    List *list17_3 = createListFromArray(arr17_3, 4);
    removeDuplicate(list17_3);
    int expectedArr17_3[3] = {750, 760, 770};
    List *expectedList17_3 = createListFromArray(expectedArr17_3, 3);
    assert(areListsEqual(list17_3, expectedList17_3));
    // Test case 4
    int arr17_4[2] = {780, 780};
    List *list17_4 = createListFromArray(arr17_4, 2);
    removeDuplicate(list17_4);
    int expectedArr17_4[1] = {780};
    List *expectedList17_4 = createListFromArray(expectedArr17_4, 1);
    assert(areListsEqual(list17_4, expectedList17_4));
    // Test case 5
    int arr17_5[1] = {790};
    List *list17_5 = createListFromArray(arr17_5, 1);
    removeDuplicate(list17_5);
    int expectedArr17_5[1] = {790};
    List *expectedList17_5 = createListFromArray(expectedArr17_5, 1);
    assert(areListsEqual(list17_5, expectedList17_5));
    // Test case 6
    List *emptyList17 = new List();
    removeDuplicate(emptyList17);
    assert(emptyList17->p_head == nullptr && emptyList17->p_tail == nullptr);
    // free memory
    freeList(expectedList17);
    freeList(expectedList17_2);
    freeList(expectedList17_3);
    freeList(expectedList17_4);
    freeList(expectedList17_5);
    freeList(list17);
    freeList(list17_2);
    freeList(list17_3);
    freeList(list17_4);
    freeList(list17_5);
    freeList(emptyList17);
    std::cout << "Passed" << std::endl;

    // Test case 18: removeElement /////////////////////////////////////////////////////////
    std::cout << "Test removeElement: ";
    // Test case 1
    int arr18[5] = {800, 810, 820, 830, 840};
    List *list18 = createListFromArray(arr18, 5);
    assert(removeElement(list18, 820));
    int expectedArr18[4] = {800, 810, 830, 840};
    List *expectedList18 = createListFromArray(expectedArr18, 4);
    assert(areListsEqual(list18, expectedList18));
    // Test case 2
    int arr18_2[3] = {850, 860, 870};
    List *list18_2 = createListFromArray(arr18_2, 3);
    assert(removeElement(list18_2, 850));
    int expectedArr18_2[2] = {860, 870};
    List *expectedList18_2 = createListFromArray(expectedArr18_2, 2);
    assert(areListsEqual(list18_2, expectedList18_2));
    // Test case 3
    int arr18_3[4] = {880, 890, 900, 910};
    List *list18_3 = createListFromArray(arr18_3, 4);
    assert(removeElement(list18_3, 910));
    int expectedArr18_3[3] = {880, 890, 900};
    List *expectedList18_3 = createListFromArray(expectedArr18_3, 3);
    assert(areListsEqual(list18_3, expectedList18_3));
    // Test case 4
    int arr18_4[2] = {920, 930};
    List *list18_4 = createListFromArray(arr18_4, 2);
    assert(removeElement(list18_4, 920));
    int expectedArr18_4[1] = {930};
    List *expectedList18_4 = createListFromArray(expectedArr18_4, 1);
    assert(areListsEqual(list18_4, expectedList18_4));
    // Test case 5
    int arr18_5[1] = {940};
    List *list18_5 = createListFromArray(arr18_5, 1);
    assert(removeElement(list18_5, 940));
    // Test case 6
    List *emptyList18 = new List();
    assert(!removeElement(emptyList18, 950)); // Remove from empty list
    assert(emptyList18->p_head == nullptr && emptyList18->p_tail == nullptr);
    // free memory
    freeList(expectedList18);
    freeList(expectedList18_2);
    freeList(expectedList18_3);
    freeList(expectedList18_4);
    freeList(list18);
    freeList(list18_2);
    freeList(list18_3);
    freeList(list18_4);
    freeList(list18_5);
    freeList(emptyList18);
    std::cout << "Passed" << std::endl;
    std::cout << "--- End running test cases ---" << std::endl;
    return 0;
}
