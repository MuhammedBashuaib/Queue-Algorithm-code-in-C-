#include <iostream>

using namespace std;

const int MaxSize = 10;

class Queue
{
private:
    int count;
    int front;
    int rear;
    int item[MaxSize];

public:
    Queue()
    {
        count = 0;
        rear = MaxSize - 1;
        front = 0;
    }

    //Item is added to the rear of the Queue. if the Queue is full return Overflow
    void Append(int number)
    {
        if (count >= MaxSize)
            cout<<"the Queue is Overflow."<<endl;
        else
            {
                rear = (rear + 1) % MaxSize;
                count++;
                item[rear] = number;
                cout<<"the append is successfully"<<endl;
            }
    }

    //The front of the Queue is removed. if the Queue is empty return Underflow.
    void Serve()
    {
        if (count <= 0)
            cout<<"the Queue is Underflow."<<endl;
        else
        {
            front = (front + 1) % MaxSize;
            count--;
            cout<<"the serve is successfully"<<endl;
        }
    }

    //Return the number of entries in the Queue.
    int Size()
    {
        return count;
    }

    //Return true if the Queue is full, otherwise return false.
    bool Full()
    {
        return count == MaxSize;
    }

    //Return true if the Queue is empty, otherwise return false.
    bool Empty()
    {
        return count == 0;
    }

    //Clears all Queue elements, You initialize the Queue.
    void Clear()
    {
        count = 0;
        rear = MaxSize - 1;
        front = 0;
        cout<<"The Queue content has been cleared successfully"<<endl;
    }

    //Displays all the elements of an Queue.
    void Display()
    {
        if (count <= 0)
            cout<<"The Queue is Underflow"<<endl;
        else
        {
            cout<<"The Queue elements is:"<<endl<<">> ";
            for (int i = front; i != rear; i = (i + 1) % MaxSize)
            {
                cout<<item[i]<<"\t";
            }
            cout<<item[rear]<<endl;
        }
    }
};

int main()
{
    Queue queue;
    int option, value;
    cout<<"\t\t<<{Welcome to the Queue program}>>"<<endl;
    system("color 3");
        while(true)
    {
        cout<<"Option:"<<endl;
        cout<<"\t1- Append."<<endl
            <<"\t2- Serve."<<endl
            <<"\t3- Clear."<<endl
            <<"\t4- Display."<<endl
            <<"\t5- Size."<<endl
            <<"\t6- is it Full?."<<endl
            <<"\t7- is it Empty?."<<endl
            <<"\t8- Exit"<<endl;
        cout<<"Choose the desired option number(1, 2, 3, 4, 5, 6, 7 or 8):"<<endl<<">>";
        cin>>option;
        switch(option)
        {
        case 1:
            system("cls");
            system("color a");
            cout<<"enter the number: ";
            cin>>value;
            queue.Append(value);
            cout<<endl<<endl;
            break;
        case 2:
            system("cls");
            system("color 5");
            queue.Serve();
            cout<<endl<<endl;
            break;
        case 3:
            system("cls");
            system("color 4");
            queue.Clear();
            cout<<endl<<endl;
            break;
        case 4:
            system("cls");
            system("color E");
            queue.Display();
            cout<<endl<<endl;
            break;
        case 5:
            system("cls");
            system("color F");
            cout<<"the stack size is: "<<queue.Size()<<endl;
            cout<<endl<<endl;
            break;
        case 6:
            system("cls");
            if(queue.Full())
                cout<<"the stack is full";
            else
                cout<<"the stack is not full";
            cout<<endl<<endl;
            break;
        case 7:
            system("cls");
            if(queue.Empty())
                cout<<"the stack is empty";
            else
                cout<<"the stack is not empty";
            cout<<endl<<endl;
            break;
        case 8:
            system("color 7");
            return 0;
            break;
        default:
            system("cls");
            system("color 7");
            cout<<"the option is not fount.. try again."<<endl;
            cout<<endl<<endl;
            break;
        }
    }
}
