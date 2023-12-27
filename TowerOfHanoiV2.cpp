#include<iostream>
#include<limits>
using namespace std;

void CheckInput(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int first[8];
int second[8];
int third[8];
int *arr[4]={0, first, second, third};
int top[4];
int value;
int counter;
int counterCheck;

void push(int column){
    arr[column][top[column]]=value;
    top[column]++;
}

void pop(int column){
    top[column]--;
    value=arr[column][top[column]];
}

void display(){
    cout<<"Counter: "<<counter<<"\n\n";
    for(int i=7; i>=0; i--){
        for(int j=1; j<4; j++){
            if(i<top[j]){
                cout<<"|";
                for(int k=arr[j][i]/2; k<4; k++){
                    cout<<"  ";
                }
                cout<<" ";
                if(arr[j][i]%2==0){
                    cout<<" ";
                }
                for(int k=0; k<arr[j][i]; k++){
                    if(arr[j][i]==1){
                        cout<<"\x1b[31m--\x1b[0m";
                    }
                    else if(arr[j][i]==2){
                        cout<<"\x1b[32m--\x1b[0m";
                    }
                    else if(arr[j][i]==3){
                        cout<<"\x1b[33m--\x1b[0m";
                    }
                    else if(arr[j][i]==4){
                        cout<<"\x1b[34m--\x1b[0m";
                    }
                    else if(arr[j][i]==5){
                        cout<<"\x1b[35m--\x1b[0m";
                    }
                    else if(arr[j][i]==6){
                        cout<<"\x1b[36m--\x1b[0m";
                    }
                    else if(arr[j][i]==7){
                        cout<<"\x1b[37m--\x1b[0m";
                    }
                    else if(arr[j][i]==8){
                        cout<<"\x1b[2m--\x1b[0m";
                    }
                }
                for(int k=arr[j][i]/2; k<4; k++){
                    cout<<"  ";
                }
                cout<<" ";
                if(arr[j][i]%2==0){
                    cout<<" ";
                }
                cout<<"|  ";
            }
            else{
                cout<<"|";
                for(int j=0; j<10; j++){
                    cout<<"  ";
                }
                cout<<"|  ";
            }
        }
        cout<<endl;
    }
}

void game(){
    counter=0;
    top[3]=0;
    top[2]=0;
    for(int i=0; i<8; i++){
        second[i]=0;
        third[i]=0;
    }
    int disk=0;
    int column;
    cout<<"Pick the number of disk you want to play with (3-8): ";
    while(disk<3 || disk>8){
        cin>>disk;
        CheckInput();
        if(disk<3 || disk>8){
            cout<<"Please pick between 3 and 8: ";
        }
    }
    top[1]=disk;
    int j=disk;
    for(int i=0; i<disk; i++){
        first[i]=j;
        j--;
    }
    while(top[3]<disk){
        system("cls");
        display();
        while(true){
            cout<<"Pop from which column? ";
            cin>>column;
            CheckInput();
            if(column==1 || column==2 || column==3){
                if(top[column]>0){
                    pop(column);
                    counterCheck=column;
                    break;
                }
                else{
                    cout<<"No disk in that column, please try again."<<endl;
                }
            }
            else{
                cout<<"There are only 3 columns"<<endl;
            }
        }
        column=0;
        while(true){
            cout<<"Push into which column? ";
            cin>>column;
            CheckInput();
            if(column==1 || column==2 || column==3){
                if(top[column]-1<0){
                    push(column);
                    break;
                }
                if(arr[column][top[column]-1]>value){
                    push(column);
                    break;
                }
                else{
                    cout<<"Cannot put larger disk over smaller disk."<<endl;
                }
            }
            else{
                cout<<"There are only 3 columns"<<endl;
            }
        }
        if(counterCheck!=column){
            counter++;
        }
    }
    system("cls");
    display();
    cout<<"You win!"<<endl;
}

void howTo(){
    system("cls");
    cout<<"------------------\n\n\n";
    cout<<"1. Only one disk can be moved at a time."<<endl;
    cout<<"2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack.\n   In other words, a disk can only be moved if it is the uppermost disk on a stack."<<endl;
    cout<<"3. No larger disk may be placed on top of a smaller disk.\n\n\n";
}

void credits(){
    system("cls");
    cout<<"------------------\n\n\n";
    cout<<"Made by Norng \"Hiva\" Sovannara."<<endl;
    cout<<"I'm also quite fond of dogs.\n\n\n";
}

void menu(){
    int option;
    while(option!=4){
        cout<<"------------------"<<endl;
        cout<<"1. Start game"<<endl;
        cout<<"2. How to play"<<endl;
        cout<<"3. Credits"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"------------------"<<endl;
        cout<<"Choose option: ";
        cin>>option;
        CheckInput();
        switch(option){
            case 1: 
            game();
            break;
            case 2:
            howTo();
            break;
            case 3:
            credits();
            break;
            case 4:
            system("cls");
            cout<<"Bye";
            break;
            default:
            system("cls");
            cout<<"Invalid reponse. Please try again."<<endl;
        }
    }
}

int main(){

    menu();

    return 0;
}