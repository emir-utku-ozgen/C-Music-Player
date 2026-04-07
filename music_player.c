#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
struct Song{
    char name[50];
    char artist[50];
    int duration;
    struct Song* next;
}typedef song;

song* createNode(char *name,char *artist,int duration){
    song* new=(song*)malloc(sizeof(song));
    strcpy(new->name,name);
    strcpy(new->artist,artist);
    new->duration=duration;
    new->next=NULL;
    return new;
}
void insertNode(song** head,char* name,char* artist,int duration){
    song* newSong=createNode(name,artist,duration);
    if(*head==NULL || strcmp((*head)->name,name)>0){
        newSong->next=*head;
        *head=newSong;
        return ;
    }
    song* iter=*head;
    while(iter->next!=NULL && strcmp(iter->next->name,name)<0){
        iter=iter->next;
    }
    newSong->next=iter->next;
    iter->next=newSong;
    return;
}
void deleteNode(song** head,char* name){
    if(*head==NULL){
        return ;
    }
    if(strcmp((*head)->name,name)==0){
        song* temp=*head;
        *head=(*head)->next;
        free(temp);
        return;
        }
    song* iter=*head;
    while(iter->next!=NULL && strcmp(iter->next->name,name)!=0){
        iter=iter->next;
    }
  if (iter->next != NULL) {
        song* temp = iter->next;            
        iter->next = iter->next->next;    
        free(temp);                        
        printf("Sarkı basarıyla silindi.\n");
    } 
    else {
        // Eğer iter->next NULL ise liste bitti ama şarkı bulunamadı demektir
        printf("Hata: '%s' isminde bir sarkı çalma listesinde yok!\n", name);
    }
}
void reversePlaylist(song** head){
    song* prev=NULL;
    song* current=*head;
    song* next=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    *head=prev;
    printf("Liste başarıyla ters çevrildi");
    return ;
}
void swapNode(song** head,char* name1,char* name2){
    if(strcmp(name1,name2)==0){
        return ;
    }
    song* prev1=NULL;
    song* curr1=*head;
    while(curr1!=NULL && strcmp(curr1->name,name1)!=0){
        prev1=curr1;
        curr1=curr1->next;
    }
    song* prev2=NULL;
    song* curr2=*head;
    while(curr2!=NULL && strcmp(curr2->name,name2)!=0){
        prev2=curr2;
        curr2=curr2->next;
    }
    if(curr1==NULL || curr2==NULL){
        return ;
    }
    if(prev1!=NULL){
        prev1->next=curr2;
    }else{
        *head=curr2;
    }
    if(prev2!=NULL){
        prev2->next=curr1;
    }else{
        *head=curr1;
    }
    if (curr1->next == curr2) {
        curr1->next = curr2->next;
        curr2->next = curr1;
    } 
    else if (curr2->next == curr1) { 
        curr2->next = curr1->next;
        curr1->next = curr2;
    } 
    else { 
        song* temp = curr2->next;
        curr2->next = curr1->next;
        curr1->next = temp;
    }
}
void shufflePlaylist(song** head){
    if((*head)==NULL || (*head)->next==NULL){
        return ;
    }
    int count=0;
    song* iter=*head;
    while(iter!=NULL){
        count++;
        iter=iter->next;
    }
    srand(time(NULL));
    for(int i=0;i<count*2;i++){
        int index1=rand()%count;
        int index2=rand()%count;
        if(index1==index2){
            continue;
        }
        char name1[50],name2[50];
        song* temp1=*head;
        song* temp2=*head;
        for(int j=0;j<index1;j++){
            temp1=temp1->next;
        }
        for(int k=0;k<index2;k++){
            temp2=temp2->next;
        }
        strcpy(name1,temp1->name);
        strcpy(name2,temp2->name);
        swapNode(head,name1,name2);
    }
    printf("Liste başarıyla karıştırıldı");
    return;
}
void clearPlaylist(song** head){
    song* iter=*head;
    while(iter!=NULL){
        song* temp=iter;
        iter=iter->next;
        free(temp);
    }
    *head=NULL ;
}
void searchByArtist(song* head,char* artist){
    int found=0;
    song* iter=head;
    while(iter!=NULL){
        if(strcmp(iter->artist,artist)==0){
            printf("- %s (%d sn)\n", iter->name, iter->duration);
            found=1;
        }
        iter=iter->next;
    }
    if(!found){
        printf("Bu sanatçıya ait eser bulunamadı!\n");
    }
}
void showStats(song* head){
    if(head==NULL){
        printf("Liste boş kanka.\n");
        return ;
    }
    int count=0;
    int totalDuration=0;
    song* max=head;
    song* iter=head;
    while(iter!=NULL){
        count++;
        totalDuration+=iter->duration;
        if((iter->duration)>max->duration){
            max=iter;
        }
        iter=iter->next;
    }
    int min=totalDuration/60;
    int sec=totalDuration%60;
    printf("\n======= PLAYLIST ÖZETİ =======\n");
    printf("Toplam Şarkı Sayısı : %d\n", count);
    printf("Toplam Çalma Süresi : %d dakika %d saniye\n", min, sec);
    printf("Zirvedeki Şarkı     : %s (%d sn)\n", max->name, max->duration);
    printf("==============================\n");

}
void playPlaylist(song* head){
    if(head==NULL){
        printf("\nÇalma listesi boş kanka önce şarkı ekle\n");
        return ;
    }
    song* iter=head;
    printf("\n======= 🎧 MÜZİK BAŞLIYOR  =======\n");
    while(iter!=NULL){
        printf("\n>>> Şu an çalıyor: %s - %s ", iter->name, iter->artist);
        fflush(stdout); 

        sleep(2); 

        printf(" [BİTTİ]");
        iter = iter->next;
    }
    printf("\n\n======= ✅ LİSTE SONA ERDİ =======\n");
}
void displayPlayList(song* head){
    if(head==NULL){
        printf("Liste boş kanka \n");
        return ;
    }
    printf("\n---------- PLAYLIST ----------\n");
    int i=1;
    song* iter=head;
    while(iter!=NULL){
        printf("%d. %s - %s [%d sn]\n", i++, iter->name, iter->artist, iter->duration);
        iter = iter->next;
    }
    printf("------------------------------\n");
}




int main() {
    song* myPlaylist = NULL;
    int choice;
    char name[50], artist[50], name2[50];
    int duration;

    insertNode(&myPlaylist, "Bohemian Rhapsody", "Queen", 354);
    insertNode(&myPlaylist, "Starboy", "The Weeknd", 230);
    insertNode(&myPlaylist, "Vazgectim", "Sezen Aksu", 312);

    while (1) {
        printf("\n--- 🎵 MY MAC PLAYLIST MANAGER ---");
        printf("\n1.Ekle 2.Sil 3.Swap 4.Reverse 5.Shuffle 6.Ara 7.Stats 8.Play 9.Listele 0.Cikis");
        printf("\nSeciminiz: ");
        
        if (scanf("%d", &choice) != 1) { 
            while(getchar() != '\n'); 
            printf("\nHata: Lütfen sadece listedeki rakamlardan birini gir kanka!\n");
            continue; 
        }
        getchar(); 

        switch (choice) {
            case 1: 
                printf("Şarkı Adı: "); scanf(" %[^\n]", name);
                printf("Sanatçı: "); scanf(" %[^\n]", artist);
                printf("Süre (sn): "); scanf("%d", &duration);
                insertNode(&myPlaylist, name, artist, duration);
                printf(">>> Eklendi!\n");
                break;

            case 2: 
                printf("Silinecek Şarkı Adı: "); scanf(" %[^\n]", name);
                deleteNode(&myPlaylist, name);
                break;

            case 3: 
                printf("1. Şarkı Adı: "); scanf(" %[^\n]", name);
                printf("2. Şarkı Adı: "); scanf(" %[^\n]", name2);
                swapNode(&myPlaylist, name, name2);
                printf(">>> Takas işlemi denendi.\n");
                break;

            case 4: 
                reversePlaylist(&myPlaylist);
                
                break;

            case 5: 
                shufflePlaylist(&myPlaylist);
                break;

            case 6: 
                printf("Aranacak Sanatçı Adı: "); scanf(" %[^\n]", artist);
                searchByArtist(myPlaylist, artist);
                break;

            case 7: 
                showStats(myPlaylist);
                break;

            case 8: 
                playPlaylist(myPlaylist);
                break;

            case 9: 
                displayPlayList(myPlaylist);
                break;

            case 0: 
                clearPlaylist(&myPlaylist);
                printf("Güle güle kanka! MacBook huzurla kapanır.\n");
                return 0;

            default:
                printf("Geçersiz seçim, menüdeki rakamlardan birini kullan kanka!\n");
        }
    }
    return 0;
}