#include <iostream>
#include "chapter3/SeqQueue.h"
using namespace std;

int main() {
    SeqQueue seqQueue;
    for (int i = 0; i < 10; ++i) {
        seqQueue.EnQueue(i);
    }

    cout<<seqQueue.IsEmpty()<<seqQueue.IsFull()<<seqQueue.getSize();
    return 0;
}
