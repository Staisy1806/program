#include <iostream>
#include <string>
using namespace std;

class Program
{
    public:

    // Завдання 1. Виведення рядка у зворотному порядку
    static void ReverseString(string str, int index)
    {
        if (index < 0)
            return;

        cout << str[index];

        ReverseString(str, index - 1);
    }

    // Завдання 2. Заміна місцями сусідніх вузлів
    struct ListNode
    {
        int val;
        ListNode* next;

        ListNode(int x)
        {
            val = x;
            next = nullptr;
        }
    };

    static ListNode* SwapPairs(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* first = head;
        ListNode* second = head->next;

        first->next = SwapPairs(second->next);
        second->next = first;

        return second;
    }

    static void PrintList(ListNode* head)
    {
        if (head == nullptr)
            return;

        cout << head->val << " ";

        PrintList(head->next);
    }

    // Завдання 3. Числа Фібоначчі
    static int Fibonacci(int n)
    {
        if (n == 0)
            return 0;

        if (n == 1)
            return 1;

        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }

    // Завдання 4. Підйом сходами
    static int ClimbStairs(int n)
    {
        if (n == 1)
            return 1;

        if (n == 2)
            return 2;

        return ClimbStairs(n - 1) + ClimbStairs(n - 2);
    }

    // Завдання 5. Власна функція піднесення до степеня
    static double MyPow(double x, int n)
    {
        if (n == 0)
            return 1;

        if (n < 0)
            return 1.0 / MyPow(x, -(n + 1)) / x;

        return x * MyPow(x, n - 1);
    }
};

int main()
{
    // Завдання 1
    cout << "Task 1:" << endl;
    string str = "tiger";
    Program::ReverseString(str, str.length() - 1);

    // Завдання 2
    cout << "\n\nTask 2:" << endl;
    Program::ListNode* head = new Program::ListNode(1);
    head->next = new Program::ListNode(2);
    head->next->next = new Program::ListNode(3);
    head->next->next->next = new Program::ListNode(4);

    head = Program::SwapPairs(head);
    Program::PrintList(head);

    // Завдання 3
    cout << "\n\nTask 3:" << endl;
    cout << Program::Fibonacci(4);

    // Завдання 4
    cout << "\n\nTask 4:" << endl;
    cout << Program::ClimbStairs(3);

    // Завдання 5
    cout << "\n\nTask 5:" << endl;
    cout << Program::MyPow(2, -2);

    return 0;
}
