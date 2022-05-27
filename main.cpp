#include <SFML\Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <windows.h>
#include <conio.h>

using namespace std;

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void printsortvect(vector <int> arr, int n, sf::RenderWindow* window)
{
    window->hasFocus();
    sf::RectangleShape rect;
    rect.setPosition(0, (float)window->getSize().y);

    for (int i = 0; i < n; i++)
    {
        rect.setSize({ (float)window->getSize().x / n, (float)arr[i] });
        rect.setRotation(180);
        rect.move((float)window->getSize().x / n, 0);  
        rect.setFillColor(sf::Color::White);
       
        window->draw(rect);

    }
    window->display();
}

void printsortarr(int * arr, int n, sf::RenderWindow* window)
{
    window->hasFocus();
    sf::RectangleShape rect;
    rect.setPosition(0, (float)window->getSize().y);

    for (int i = 0; i < n; i++)
    {
        rect.setSize({ (float)window->getSize().x / n, (float)arr[i] });
        rect.setRotation(180);
        rect.move((float)window->getSize().x / n, 0);
        rect.setFillColor(sf::Color::White);

        window->draw(rect);

    }
    window->display();
}

void printArr(vector<int> arr, sf::RenderWindow* window, int code, int x, int y, int n)
{
    window->hasFocus();
    sf::RectangleShape rect;
    rect.setPosition(0, (float)window->getSize().y);

    for (int i = 0; i < n; i++)
    {
        rect.setSize({ (float)window->getSize().x / n, (float)arr[i] });
        rect.setRotation(180);
        rect.move((float)window->getSize().x / n, 0);

        if (code == 1)
        {
            if (i == y || i == x) rect.setFillColor(sf::Color::Yellow);
            else rect.setFillColor(sf::Color::White);
        }
        else if (code == 2)
        {
            if (i == y || i == x) rect.setFillColor(sf::Color::Green);
            else rect.setFillColor(sf::Color::White);
        }
        else
        {
            if (i == y || i == x) rect.setFillColor(sf::Color::Red);
            else rect.setFillColor(sf::Color::White);
        }
        window->draw(rect);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window->close();

    }
    window->display();
}

void bubblesort(vector <int> arr, int n)
{
    sf::RenderWindow window(sf::VideoMode(1280, 800), "Why are you like this", sf::Style::Fullscreen);
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j+1] < arr[j])
            {
                window.clear();
                printArr(arr, &window, 1, j, j+1, n);
                swap(&arr[j], &arr[j + 1]);
                window.clear();
                printArr(arr, &window, 2, j, j+1, n);
            }

            else
            {
                //window.setFramerateLimit(60);
                window.clear();
                printArr(arr, &window, 0, j, j+1, n);
            }
        }
    }
   
    while (1)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
            break;
        }
        printsortvect(arr, n, &window);
    }
    
    return;
}

void selectionsort(vector <int> arr, int n)
{
    sf::RenderWindow window(sf::VideoMode(1280, 800), "Why are you like this", sf::Style::Fullscreen);

    int min;
    for (int i = 0; i < n; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
                window.clear();
                printArr(arr, &window, 1, min, j, n);
            }
        }

        swap(&arr[min], &arr[i]);
        window.clear();
        printArr(arr, &window, 0, min, i, n);
    }

    while (1)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
            break;
        }
        printsortvect(arr, n, &window);
    }

    return;
}

void printiArr(vector <int> arr, int x, char ch, sf::RenderWindow* window, int s)
{
    window->hasFocus();
    sf::RectangleShape rect;
    rect.setPosition(0, (float)window->getSize().y);


    for (int i = 0; i < s; i++)
    {
        rect.setSize({ (float)window->getSize().x / s,(float)arr[i] });
        rect.setRotation(180);
        rect.move((float)window->getSize().x / s, 0);

        if (i == x && ch != 'w')
        {
            if (ch == 'w') rect.setFillColor(sf::Color::White);
            else {
                if (ch == 'r') rect.setFillColor(sf::Color::Red);
                else if (ch == 'p') rect.setFillColor(sf::Color(100, 0, 100, 255));
                else if (ch == 'g') rect.setFillColor(sf::Color::Green);
            }
        }
        else
        {
            rect.setFillColor(sf::Color::White);
        }
        window->draw(rect);
    }
    window->display();
}

void insertionsort(vector <int> arr, int s)
{
    sf::RenderWindow window(sf::VideoMode(1280, 800), "Why are you like this", sf::Style::Fullscreen);
    sf::RectangleShape rect;

    for (int j = 1; j < s; j++)
    {
        int i = 0;

        window.clear();
        printiArr(arr, j, 'g', &window, s);

        while (arr[j] > arr[i])
        {
            i = i + 1;
            window.clear();
            printiArr(arr, j, 'r', &window, s);

        }

        int temp = arr[j];

        for (int k = 0; k <= j - i - 1; k++)
        {
            int a;
            a = arr[j - k];
            arr[j - k] = arr[j - k - 1];
            arr[j - k - 1] = a;

            window.clear();
            printiArr(arr, j, 'p', &window, s);

            arr[i] = temp;

        }
    }

    while (1)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
            break;
        }
        printsortvect(arr, s, &window);
    }

    return;
}

void printmArr(int *arr, int x, int y, int code, sf::RenderWindow* window, int s)
{
    window->hasFocus();
    sf::RectangleShape rect;
    rect.setPosition(0, (float)window->getSize().y);

    for (int i = 0; i < s; i++)
    {
        rect.setSize({ (float)window->getSize().x / s, (float)(((float)arr[i] / 1080) * (float)window->getSize().y) });
        rect.setRotation(180);
        rect.move((float)window->getSize().x / s, 0);

        if (code == 1)
        {
            if (i == x)
            {
                rect.setFillColor(sf::Color::Red);
            }
            else
            {
                rect.setFillColor(sf::Color::White);
            }
            window->draw(rect);
        }

        else if (code == 0)
        {

            if (i == x || i == y)
            {
                rect.setFillColor(sf::Color::Green);

            }
            else
            {
                rect.setFillColor(sf::Color::White);
            }
            window->draw(rect);
        }
    }
    window->display();

}

void merge(int *arr, int begin, int mid, int end, int n, sf::RenderWindow* window)
{
    int left = mid - begin + 1;
    int right = end - mid;
    int smol[10000]={0}, big[10000]={0};

    for (int i = 0; i < left; i++)
    {
        smol[i] = arr[begin + i];

    }
    for (int i = 0; i < right; i++)
    {
        big[i] = arr[mid + 1 + i];

    }

    int i = 0, j = 0, k = begin;

    while (i < left && j < right)
    {
        if (smol[i] <= big[j])
        {
            arr[k] = smol[i];
            i++;
            k++;
            window->clear();
            printmArr(arr, k, 0, 1, window, n);
        }
        else
        {
            arr[k] = big[j];
            j++;
            k++;
            window->clear();
            printmArr(arr, k, 0, 1, window, n);

        }
    }

    while (i < left)
    {
        arr[k] = smol[i];
        i++;
        k++;
    }

    while (j < right)
    {
        arr[k] = big[j];
        j++;
        k++;

    }
}


void mergeSort(int *arr, int begin, int end, int n, sf::RenderWindow* window)
{
    if (begin < end)
    {
        int mid = (begin + end) / 2;

        window->clear();
        printmArr(arr, begin, end, 0, window, n);
        mergeSort(arr, begin, mid, n, window);
        mergeSort(arr, mid + 1, end, n, window);

        merge(arr, begin, mid, end, n, window);
        window->clear();
        printmArr(arr, begin, end, 0, window, n);

    }

    return;
}

void printqArr(int * arr, int x, int y, int piv, sf::RenderWindow* window, int s)
{
    window->hasFocus();
    sf::RectangleShape rect;
    rect.setPosition(0, (float)window->getSize().y);

    for (int i = 0; i < s; i++)
    {
        rect.setSize({ (float)window->getSize().x / s, (float)(((float)arr[i] / 1080) * (float)window->getSize().y) });
        rect.setRotation(180);
        rect.move((float)window->getSize().x / s, 0);

        if (i == x)
        {
            rect.setFillColor(sf::Color::Red);

        }
        else if (i == piv)
        {
            rect.setFillColor(sf::Color::Green);

        }
        else if (i == y)
        {
            rect.setFillColor(sf::Color::Yellow);

        }
        else
        {
            rect.setFillColor(sf::Color::White);
        }
        window->draw(rect);
    }
    window->display();

}

int partition(int *arr, int begin, int end, sf::RenderWindow* window, int n)
{
    int i = begin - 1;
    int piv = arr[end];

    for (int j = begin; j < end; j++)
    {
        if (arr[j] < piv)
        {
            i++;
            window->clear();
            printqArr(arr, i, j, end, window, n);
            swap(&arr[i], &arr[j]);
            window->clear();
            printqArr(arr, i, j, end, window, n);
        }
    }

    window->clear();
    printqArr(arr, i + 1, end, end, window, n);
    swap(&arr[i + 1], &arr[end]);
    window->clear();
    printqArr(arr, i + 1, end, end, window, n);
    return i + 1;
}

void quickSort(int *arr, int begin, int end, sf::RenderWindow* window, int n)
{
    if (begin < end)
    {
        int p = partition(arr, begin, end, window, n);

        quickSort(arr, begin, p - 1, window, n);
        window->clear();
        window->hasFocus();
        sf::RectangleShape rect;
        rect.setPosition(0, (float)window->getSize().y);

        for (int i = 0; i < n; i++)
        {
            rect.setSize({ (float)window->getSize().x / n, (float)arr[i] });
            rect.setRotation(180);
            rect.move((float)window->getSize().x / n, 0);

            if (i == begin || i == (p-1)) rect.setFillColor(sf::Color::Red);
            else rect.setFillColor(sf::Color::White);
            window->draw(rect);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window->close();

        }
        window->display();

        quickSort(arr, p + 1, end, window, n);
        window->clear();
        rect.setPosition(0, (float)window->getSize().y);

        for (int i = 0; i < n; i++)
        {
            rect.setSize({ (float)window->getSize().x / n, (float)arr[i] });
            rect.setRotation(180);
            rect.move((float)window->getSize().x / n, 0);

            if (i == (p+1) || i == end) rect.setFillColor(sf::Color::Red);
            else rect.setFillColor(sf::Color::White);
            window->draw(rect);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window->close();

        }
        window->display();

    }

    return;
}



int main()
{
    vector <int> arr;
    int n;
    int v[10000];

    FILE* numFile;

    fopen_s(&numFile, "numbers.txt", "r");
    char opt;
  
    while (1)
    {
        //system("cls");
        cout << "\n\t:Press 'B' for Bubble Sort.\n\t:Press 'S' for Selection Sort.\n\t:Press 'I' for Insertion Sort.\n\t:Press 'M' for Merge Sort.\n\t:Press 'Q' for Quick Sort.\n\t:Press 'E' to exit.\n>>>>> ";
        cin >> opt;
        
        if (opt == 'B')
        {
            system("cls");
            cout << "Enter the number of data (max 10000/recommended 100): \n";
            while (1)
            {
                cout << ">>>>> ";
                cin >> n;
                if (n <= 10000 && n > 0) break;
                cout << "Invalid number. Please try again.\n";
            }
            for (int i = 0; i < n; i++)
            {
                int x;
                fscanf_s(numFile, "%d", &x);
                arr.push_back(x);
                v[i] = x;
            }
            cout << "Now implementing, BUBBLE SORT!\n";
            bubblesort(arr, n);
            system("cls");
        }
        else if (opt == 'S')
        {
            system("cls");
            cout << "Enter the number of data (max 10000/recommended 1000): \n";
            while (1)
            {
                cout << ">>>>> ";
                cin >> n;
                if (n <= 10000 && n > 0) break;
                cout << "Invalid number. Please try again.\n";
            }
            for (int i = 0; i < n; i++)
            {
                int x;
                fscanf_s(numFile, "%d", &x);
                arr.push_back(x);
                v[i] = x;
            }
            cout << "Now implementing, SELECTION SORT!\n";
            selectionsort(arr, n);
            system("cls");
        }
        else if (opt == 'I')
        {
            system("cls");
            cout << "Enter the number of data (max 10000/recommended 50): \n";
            while (1)
            {
                cout << ">>>>> ";
                cin >> n;
                if (n <= 10000 && n > 0) break;
                cout << "Invalid number. Please try again.\n";
            }
            for (int i = 0; i < n; i++)
            {
                int x;
                fscanf_s(numFile, "%d", &x);
                arr.push_back(x);
                v[i] = x;
            }
            cout << "Now implemeting, INSERTION SORT!\n";
            insertionsort(arr, n);    
            system("cls");
        }
        else if (opt == 'M')
        {
            system("cls");
            cout << "Enter the number of data (max 10000/recommended ANY): \n";
            while (1)
            {
                cout << ">>>>> ";
                cin >> n;
                if (n <= 10000 && n > 0) break;
                cout << "Invalid number. Please try again.\n";
            }
            for (int i = 0; i < n; i++)
            {
                int x;
                fscanf_s(numFile, "%d", &x);
                arr.push_back(x);
                v[i] = x;
            }
            cout << "Now implementing, MERGE SORT!\n";
            sf::RenderWindow window(sf::VideoMode(1280, 800), "Why are you like this", sf::Style::Fullscreen);
            mergeSort(v, 0, n, n, &window);

            while (1)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
                    window.close();
                    break;
                }
                printsortarr(v, n, &window);
            }
            system("cls");
        }
        else if (opt == 'Q')
        {
            system("cls");
            cout << "Enter the number of data (max 10000/recommended ANY): \n";
            while (1)
            {
                cout << ">>>>> ";
                cin >> n;
                if (n <= 10000 && n > 0) break;
                cout << "Invalid number. Please try again.\n";
            }
            for (int i = 0; i < n; i++)
            {
                int x;
                fscanf_s(numFile, "%d", &x);
                arr.push_back(x);
                v[i] = x;
            }
            cout << "Now implementing, QUICK SORT!\n";
            sf::RenderWindow window(sf::VideoMode(1280, 800), "Why are you like this", sf::Style::Fullscreen);
            quickSort(v, 0, n - 1, &window, n);

            while (1)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
                    window.close();
                    break;
                }
                printsortarr(v, n, &window);
            }
            system("cls");
        }
        else if (opt == 'E') break;
        else
        {
            cout << "\n\tWrong option! Try again.\n"; 
        }
 
    }
	
	return 0;
}