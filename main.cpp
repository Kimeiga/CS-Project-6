////1a
//
#include <iostream>

using namespace std;
//
//int main()
//{
//    int arr[3] = { 5, 10, 15 };
//    int* ptr = arr;
//
//    *ptr = 30;          // set arr[0] to 30
//    *(ptr + 1) = 20;      // set arr[1] to 20
//    ptr += 2;
//    ptr[0] = 10;        // set arr[2] to 10
//
//
//    while (ptr >= arr)
//    {
//        cout << arr[(arr - ptr + 2)] << endl;    // print values
//        ptr--;
//    }
//}

//1b
//
//void findMax(int arr[], int n, int*& pToMax)
//{
//    if (n <= 0)
//        return;      // no items, no maximum!
//
//    pToMax = arr;
//
//    for (int i = 1; i < n; i++)
//    {
//        if (arr[i] > *pToMax)
//            pToMax = arr + i;
//    }
//}
//
//int main()
//{
//    int nums[4] = { 5, 3, 15, 6 };
//    int* ptr;
//
//    findMax(nums, 4, ptr);
//    cout << "The maximum is at address " << ptr << endl;
//    cout << "It's at position " << ptr - nums << endl;
//    cout << "Its value is " << *ptr << endl;
//}

//1c

//segmentation fault when you try to access object of uninitialized pointer
//
//void computeCube(int n, int* ncubed)
//{
//    *ncubed = n * n * n;
//}
//
//int main()
//{
//    int* ptr;
//    int integer;
//    ptr = &integer;
//    computeCube(5, ptr);
//    cout << "Five cubed is " << *ptr << endl;
//}

//1d

//must use objects of pointers in comparison if statement

//// return true if two C strings are equal
//bool strequal(const char str1[], const char str2[])
//{
//    while (str1 != 0  &&  str2 != 0)
//    {
//        if (*str1 != *str2)  // compare corresponding characters
//            return false;
//        str1++;            // advance to the next character
//        str2++;
//    }
//    return str1 == str2;   // both ended at same time?
//}
//
//int main()
//{
//    char a[15] = "Zhou";
//    char b[15] = "Zhu";
//
//    if (strequal(a,b))
//        cout << "They're the same person!\n";
//}

//1e
//
//#include <iostream>
//using namespace std;
//
//int anArray[100];
//
//int* nochange(int* p)
//{
//    return p;
//}
//
//int* getPtrToArray(int& m)
//{
//
//    for (int j = 0; j < 100; j++)
//        anArray[j] = 100-j;
//    m = 100;
//    return nochange(anArray);
//}
//
//void f()
//{
//    int junk[100];
//    for (int k = 0; k < 100; k++)
//        junk[k] = 123400000 + k;
//    junk[50]++;
//}
//
//int main()
//{
//    int n;
//    int* ptr = getPtrToArray(n);
//    f();
//    for (int i = 0; i < 3; i++)
//        cout << ptr[i] << ' ';
//    for (int i = n-3; i < n; i++)
//        cout << ptr[i] << ' ';
//    cout << endl;
//}

//
//the program is declaring a non static array within the scope of getPtrToArray and trying to return a pointer to that array
//this is not allowed, the programmer can use a global variable for the array instead to make the functionality work

//2
//double * cat;
//double mouse[5];
//cat = &mouse[4];
//
//*cat = 25;
//*(mouse + 3) = 42;
//cat -= 3;
//cat[1] = 54;
//cat[0] = 27;
//bool b = (*cat == *(cat + 1));
//bool d = (cat == mouse);


//3a
//double mean(const double* scores, int numScores)
//{
//    const double* ptr = scores;
//    int i = 0;
//    double tot = 0;
//    while ((ptr + i) != scores + numScores)
//    {
//        tot += *(ptr + i);
//        i++;
//    }
//    return tot/numScores;
//}

///3b
// This function searches through str for the character chr.
// If the chr is found, it returns a pointer into str where
// the character was first found, otherwise nullptr (not found).
//
//const char* findTheChar(const char* str, char chr)
//{
//    for (int k = 0; *(str + k) != 0; k++)
//        if (*(str + k) == chr)
//            return (str + k);
//
//    return nullptr;
//}

///3c
//
//const char* findTheChar(const char* str, char chr)
//{
//    while(*str != 0){
//        if(*str == chr){
//            return str;
//        }
//        str++;
//    }
//
//    return nullptr;
//}

///4

#include <iostream>
using namespace std;

int* maxwell(int* a, int* b)
{
    if (*a > *b)
        return a;
    else
        return b;
}

void swap1(int* a, int* b)
{
    int* temp = a;
    a = b;
    b = temp;
}

void swap2(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int array[6] = { 5, 3, 4, 17, 22, 19 };

    int* ptr = maxwell(array, &array[2]);
    *ptr = -1;
    ptr += 2;
    ptr[1] = 9;
    *(array+1) = 79;

    cout << &array[5] - ptr << endl;

    swap1(&array[0], &array[1]);
    swap2(array, &array[2]);

    for (int i = 0; i < 6; i++)
        cout << array[i] << endl;
}

///5
//
//void removeS(char msg[]){
//    char * c = msg;
//    for (int i = 0; *(msg + i) != '\0'; ++i) {
//        if(*(msg + i) == 'S' || *(msg + i) == 's'){
//            //current char is an s
//            for (int j = i; *(msg + j) != '\0'; ++j) {
//                //make current char have value of next char
//                *(msg + j) = *(msg + j + 1);
//            }
//            i--;
//        }
//    }
//}
//
//int main()
//{
//    char msg[50] = "She'll be a massless princess.";
//    removeS(msg);
//    cout << msg;  // prints   he'll be a male prince.
//}