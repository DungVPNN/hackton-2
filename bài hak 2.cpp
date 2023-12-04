#include<stdio.h>
#include<string.h>
struct contactList{
	int id;
	char name[50];
	char phone[12];
	char address[50];
	int status;
	
};
typedef struct contactList ff;
void input (ff*temp){
	printf("Id\n");
	scanf("%d",&temp->id);
	printf("Ten\n");
	getchar();
	gets(temp->name);
	printf("So dien thoai\n");
	gets(temp->phone);
	printf("Dia chi\n");
	gets(temp->address);
	printf("Trang thai\n");
	scanf("%d",&temp->status);
}
void output (ff*temp){
	printf("id: %d,ten: %s,so dien thoai: %s,dia chi: %s,trang thai: %d",temp->id,temp->name,temp->phone,temp->address,temp->status);
}
void arrange(contactList ff[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
           if(strcmp(ff[i].name,ff[j].name)>0)
          {
            contactList k=ff[i];
            ff[i]=ff[j];
            ff[j]=k;
          }
        }
    } 
}
int main(){
	int n,i;
	int choice;
	int index =2;
	int count;
	ff contactList[2]=
	{
		{1,"Le Dien Tien","0961511574","Dong Anh Ha Noi",1},
		{2,"Nguyen Nam Son","0886666731","Dong Anh Ha Noi",0}		
	};
	do{
		printf("\n--------------MENU-------------\n");
		printf("1.In toan bo danh sach contact co trong mang tren cung 1 hang\n");
		printf("2.Nhap them moi vao contact vao vi tri cuoi cung cua contactlist\n");
		printf("3.Cap nhat tt contact neu ko tim thay in ra ko tim thay\n");
		printf("4.Xoa 1 contact neu ko tim thay in ra ko tim thay\n");
		printf("5.Thuc hien sap xep va in ra contact da duoc sap xep\n");
		printf("6.Thuc hien tim kiem va in ra tt contact cung 1 hang\n");
		printf("7.Thuc hien tim kiem va in ra toan bo thong tin contact\n");
		printf("\nNhap lua chon:");
		scanf("%d",&choice);
		getchar();
		switch(choice){
			case 1:
				 for (i=0;i<index;i++){
                    printf("%d:",i+1);
                    output(&contactList[i]);
                    printf("\n");
                }
                break;
            case 2:
        		int add_Idcontact;
        		printf("nhap so lan them vao :");
        		scanf("%d",&add_Idcontact);
        		for (i=0;i<add_Idcontact;i++){
        		input(&contactList[index]);
        		index++;
			}
            	break;
            case 3:
            	 count=0;
            	int find_id;
                printf("nhap vao contact_id can cap nhat:");
                scanf("%d",&find_id);
                for (i=0;i<index;i++) {
                    if (contactList[i].id == find_id)
                        {input(&contactList[i]);
						count =1;
						}
    			}
    			if(count==0){
    				printf("khong tim thay\n");
				}
                break;
            case 4 :
            	 count=0;
        	int delete_id;
                printf("nhap vao id can xoa:");
                scanf("%d",&delete_id);
                for (i=0;i<index;i++) {
                    if (contactList[i].id == delete_id)
                    for (int j=i;j<index-1;j++){
                      contactList[i] = contactList [i+1];	
                    	count=1;
					}
                }
                if(count==0){
    				printf("khong tim thay\n");
				}
                index--;
                break;
            case 5:
            	arrange(contactList,index);
            	for (i=0;i<index;i++) {
                    printf("%d:",i+1);
                    output(&contactList[i]);
                    printf("\n");
                }
            	break;
		}
	}while(1==1);
} 
