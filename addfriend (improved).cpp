#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// hubungan horizontal
// -> terhubung dengan semua anggota yang terdapat di dlm sistem
// andy <-> budi <-> cindy

// hubungan vertikal
// -> terhubung dengan temannya saja
// 
// 		   |  andy     budi     cindy
// --------|--------|--------|----------
// teman 1 |  budi	|  andy	 |	budi
// teman 2 |   -	|  cindy |    -
// teman 3 |   -	|	-	 |    -

// Funtion prototype
struct user;
void addfriend(const char* , const char* );
void pushmid(char* , char* );
user* new_User(char* , char*);
user *search(const char*);

// ================================================== Perubahan ==============================================
struct user {
    char userName[255];
    char passWord[255];
    char notes[255];
    bool privat;
//    struct Friends *friends;   // daftar teman yang dimiliki , hubungan vertikal ke bawah
//    struct Friends *friendReq; // daftar orang req jadi teman, hubungan vertikal ke bawah
	user* friends;
	user* friendReq;
    user* anggota;			   // link dengan anggota2 lain  , hubungan horizontal ke samping
    user* prev, * next;
} *head = NULL, *tail = NULL;

user* new_User(char* name, char* pass) { // fungsi untuk membuat user
    user* temp = (user*)malloc(sizeof(user));
    strcpy(temp->userName, name);
    strcpy(temp->passWord, pass);
    temp->prev = temp->next = temp->anggota = NULL;
    return temp;
}

struct Friends{ // nested struct, setiap user punya linkedlist friend dan friend yang nge-request
	char nama[255];
	struct user *alamatNama;
	struct Friends *friends = NULL;
};

Friends *new_Friends(const char* name) { // fungsi untuk membuat friend
    Friends* temp = (Friends*)malloc(sizeof(Friends));
    strcpy(temp->nama, name);
	temp->friends = NULL;
    return temp;
}

void start(){ // inisiasi variable dr fungsi sebelumnya

//           user 	 pass													
//           name    word 											
	pushmid("andy" , "andy" ); // push
	pushmid("budi" , "budi" );
	pushmid("cindy", "cindy");
	printf("andy ingin berteman dengan budi\n\n");
	addfriend("andy", "budi" ); // addfriend nya cmn yg terakhir(daniel), belum bisa liked list
//	addfriend("andy", "cindy" );
//	addfriend("andy", "daniel"); 
	printf("di list friendnya andy ada: %s\n", search("andy")->friends);   //cari alamat andy lalu liat friend nya
	printf("di list request friendnya budi ada: %s\n", search("budi")->friendReq); // cari yang nama nya budi, liat siapa yang request
	printf("\n");
}

user *search(const char *a){
	user *curr = head;

	while (curr){
		if (strcmp(curr->userName, a) == 0){
			return curr;
		}
        curr = curr->next;
    }
    return NULL;
} // fungsi search nya udh bisa buat treverse linkedlist "user", return NULL atau alamat

// 				si A request berteman ke B
void addfriend(const char *a, const char *b){
	user *alamatA = search(a); // return NULL atau alamat
	user *alamatB = search(b); // return NULL atau alamat

	if (alamatA && alamatB){ // salah satu tidak boleh NULL
		// si A harus menyimpan nama B
		alamatA->friends = alamatB;
		// si B harus mengetahui si A sedang me-request
		alamatB->friendReq = alamatA;
	}
	
} // fungsi add friend nya belum bisa membentuk linked chain

// ================================================================================================================

void pushhead(char* name, char* pass) {
    user* temp = new_User(name, pass);
    if (!head) {
        head = tail = temp;
    }
    else {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void pushtail(char* name, char* pass) {
    user* temp = new_User(name, pass);
    if (!tail) {
        head = tail = temp;
    }
    else {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void pushmid(char* name, char* pass) {
    user* temp = new_User(name, pass);
    if (!head) {
        head = tail = temp;
    }
    else {
        if (strcmp(head->userName, name) > 0) {
            pushhead(name, pass);
        }
        else if (strcmp(tail->userName, name) <= 0) {
            pushtail(name, pass);
        }
        else {
            user* curr = head;
            while (curr->next && strcmp(tail->next->userName, name) > 0) {
                curr = curr->next;
            }
            if (curr == NULL) {
                return;
            }
            curr->prev->next = temp;
            temp->prev = curr->prev;
            temp->next = curr;
        }
    }
}

void printall() {
    if (!head) {
        return;
    }
    user* temp = head;
    while (temp) {
        printf("Username: %s\n", temp->userName);
        printf("Password: %s\n", temp->passWord);
        temp = temp->next;
    }
}

int main (){
	start();
	printall();
	return 0;
}

