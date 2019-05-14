/* 
nama : putri nabila 
kelas : A
NPM : 140810180007 
Tanggal pembuatan : 14-05-2019
deksripsi : Membalikkan huruf menggunakan queue(linked list)
*/
#include <iostream>
using namespace std;

struct data
{
    char info;
    data* next;
};

typedef data* pointer;

struct Queue
{
    pointer head;
    pointer tail;
};

void createQueue(Queue& Q){
    Q.head=NULL;
    Q.tail=NULL;
}

void createElement(pointer& pBaru){
    pBaru = new data;
    cout << "Masukkan Huruf : ";
    cin>> pBaru->info;
    pBaru->next = NULL;
}


void insertQueue(Queue& Q, pointer pBaru){
    if( Q.head == NULL && Q.tail == NULL){
        Q.head = pBaru;
        Q.tail = pBaru;
    }
    else
    {
        Q.tail->next = pBaru;
        Q.tail = pBaru;\
    }
}

// Sama dengan delete first
void deleteQueue(Queue& Q){
    pointer pHapus;
    // Kondisi kosong
    if( Q.head == NULL && Q.tail == NULL){
        cout << "List kosong" << endl;
	}   
    // Kondisi elementnya satu
    else if(Q.head->next==NULL){
        pHapus = Q.head;
        Q.head=NULL;
        Q.tail=NULL;
    }
    // Kondisi elementnya lebih dari satu
    else{
        pHapus = Q.head;
        Q.head = Q.head->next;
        pHapus->next = NULL;
    }
}
void cetakQueue(Queue Q){
    pointer pBantu;
    // Kondisi Kosong
    if(Q.head == NULL && Q.tail == NULL){
        cout << "List kosong" << endl;
    }
    // Kondisi ada element
    else
    {
        pBantu = Q.head;
        do
        {
            cout << pBantu->info << endl;
            pBantu = pBantu->next;
        } while (pBantu != NULL);
        
    }
}
int main()
{
    pointer p;
    int n;
	Queue Q;
	cout << "Masukkan jumlah data : "; 
	cin >> n;
	createQueue(Q);
    for(int i=0; i<n; i++){
		createElement(p);
	    insertQueue(Q,p);
	}
    cetakQueue(Q);
    return 0;
}



