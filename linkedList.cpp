#include <iostream>
#include <vector>

template<class T>
class List {
    private: 
        class Node {
            public:
                Node* next = nullptr;
                T data;

                Node() : next(nullptr), data() {} 
                Node(T value) : next(nullptr), data(value) {}
        };

        Node* head;

    public:

        List(T a) : head(new Node(a)) {}

        void insert(T data) {
            Node* n = head;

            while(n->next != nullptr) {
                n = n->next;
            }

            n->next = new Node(data);
        }

        void show() {
            Node* n = head;

            if(n == nullptr) {
                std::cout << "List empty" << std::endl;
                return;
            }

            while(n != nullptr) {
                std::cout << n->data << ",";
                n = n->next;
            }
            std::cout<<std::endl;
        }

        int size() {
            Node* n = head;
            int counter = 1;
            while(n->next != nullptr) {
                n = n->next;
                counter++;
            }
            return counter;
        }

        void del(int index) {
            int len = size();
            if(index<0 || index>(len-1)) {
                std::cout << "Can't delete " << index << "\nOut of bounds" << std::endl;
            }

            if(index==0) {
                head = head->next;
                return;
            }

            Node* prev = head;
            while(index--!=1) {
                prev = prev->next;
            }
            Node* toDelete = prev->next;
            Node* afterDel = toDelete->next;
            prev->next = afterDel;
        }

        void reverse() {
            int len = size();
            std::cout << "Size " << len << std::endl;
            std::vector<Node*> listPointer(len);
            listPointer[0] = head;

            Node *n = head;
            int counter = 1;
            while(n->next != nullptr) {
                n = n->next;
                listPointer[counter++] = n;
            }

            // n is last
            for(int i = listPointer.size()-1; i >= 1; i--) {
                //std::cout << i << std::endl;
                listPointer[i]->next = listPointer[i-1];
            }

            // WARNING!
            listPointer[0]->next = nullptr;

            head = n;
        }


        T const& operator[](int index) const {
            Node* n = head;
            int len = size();
            index %= len;
            while(n->next != nullptr && index--!=0) {
                n = n->next;
            }
            return n->data;
        }

        T& operator[](int index) {
            Node* n = head;
            int len = size();
            index %= len;
            while(n->next != nullptr && index--!=0) {
                n = n->next;
            }
            return n->data;
        }


};

// driver code
int main() {
    List<int> list(0);

    for(int i = 1; i < 15; i++) {
        list.insert(i);
    }

    list.show();

    std::cout<<std::endl;

    for(int i = 0; i<20; i++) {
        std::cout << list[i] << ",";
    }

    std::cout<<std::endl;
    
    std::cout << "Before" << std::endl;
    list.show();
    std::cout << "After" << std::endl;
    list.del(0);
    list.show();

    std::cout << "Reverse" << std::endl;
    list.reverse();
    list.show();

    list.del(1);
    list[1] = 5;
    list.show();
}
