#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

int main() {
    string op;


    int num;

    //Flags
    bool isStack = true, isQueue = true;
    bool isPriority = true;

    // s q e pq
    stack<int> s;
    queue<int> q;
    priority_queue<int> pq;

    //Lembrar do EOF
    while (cin >> op) {
        //if (op == "299") { break; }

        if (op == "add") {
            cin >> num;
            //Adicionar em todas elas
            s.push(num);
            q.push(num);
            pq.push(num);
        }
        else if (op == "pop") {
            std::cin >> num;

            //Se é valido então
            if (isStack) {
                if (s.empty() || s.top()!=num){
                    isStack = false;
                }
                else {
                s.pop();
                }

                //s.pop
            }

            if (isQueue ) {
                if (q.empty()|| q.front() != num) {
                    isQueue = false;
                }
            else {
                q.pop();

                }
            }
            //qpop here

            if (isPriority) {


                if (pq.empty() || pq.top() != num) {
                    isPriority = false;
                }
                else
                    {
                    pq.pop();
                }
        }
        }
    }

    //Flags indical ql e
    if (isStack && isQueue || isStack && isPriority || isPriority && isQueue) {
        cout << "both" << endl;
        //Essa da problema, concertar
        //Era a ultima condição, n tirar
    }
    else if (isStack && !isQueue && !isPriority){
        cout << "stack" << endl;
    }
    else if (!isStack && isQueue && !isPriority){
        cout << "queue" << endl;
    }

    else if (!isStack && !isQueue &&isPriority){
        cout << "priority" << endl;
    }else {
        cout << "none" << endl; //Conflito
        //cout << "stack " << isStack << " queue " << isQueue << " prio " << isPriority;
    }
}
