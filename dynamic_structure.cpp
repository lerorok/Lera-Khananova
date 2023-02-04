#include <iostream>
#include <iomanip>
using namespace std;
 
struct List {
    int data;
    List *prev, *next;
};

class dynamic_list {
    public:
        List * insert(List * last, List * p)
        {
            if (last && p)
            {
                p->prev = last;
                p->next = last->next;
                last->next = p;
                p->next->prev = p;
                return p;
            }
            else
                return NULL;
        }
        
        void CreateList(List *&head, List *&tail)
        {
            head = new List;
            tail = new List;
            head->next = tail;
            tail->prev = head;
            int k;
            cout << "Input positive integers(input 0 to stop): " << endl;
            cin >> k;
            List * last = head;
            while (k)
            {
                List * p = new List;
                p->data = k;
                last = insert(last, p);
                cin >> k;
            }
            return;
        }
        
        void print(List * head, List * tail){
            List * p = head->next;
            while (p != tail)
            {
                cout << p->data << " ";
                p = p->next;
            }
            cout << endl;
            return;
        }
         
         void sort(List *&head, List *&tail) {
            List *head2 = new List;
            List *tail2 = new List;
            List * last = head2;
         
            head2->next = tail2;
            tail2->prev = head2;
            while (head->next != tail)
            {
                List *min = head->next, *p = head->next;
                while (p != tail)
                {
                    if (p->data < min->data)
                        min = p;
                    p = p->next;
                }
                
                min->next->prev = min->prev;
                min->prev->next = min->next;
         
                last = insert(last, min);
            }
            head = head2;
            tail = tail2;
        }
};
 
int main()
{   
    dynamic_list dyn_list;
    
    List *head, *tail = NULL;
    
    dyn_list.CreateList(head, tail);
    
    cout << "List" << endl;
    dyn_list.print(head, tail);
    
    dyn_list.sort(head, tail);
    cout << "Sorted List" << endl;
    dyn_list.print(head, tail);
    return 0;
}
