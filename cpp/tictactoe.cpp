#include<iostream>
#include<string>
using namespace std;

// Function Prototype
void draw_grid(string code);
void read_char(string &code, char c);
int check_win(string code, char c);

// Main Function
int main(){
    cout<<"--------------------------------"<<endl;
    cout<<"   Welcome to TIC - TAC - TOE   "<<endl;
    cout<<"--------------------------------"<<endl;


cout<<"Choose a position from 1 to 9: "<<endl;

    cout<<"   |   |   "<<endl;
    cout<<"------------"<<endl;
    cout<<"   |   |   "<<endl;
    cout<<"------------"<<endl;
    cout<<"   |   |   "<<endl;
    cout<<"            "<<endl;    

    while(true){
    // 9 spaces at the beginning and it's empty
    string position_code= "         ";
   
    for(int turn=1; turn<=9; turn++){
        if(turn%2==1){
            read_char(position_code,'X');
            draw_grid(position_code);

            // check if X won

            if(check_win(position_code, 'X')==1){
                cout<<"Player X wins! "<<endl;
                break;
            }
        }
        
        else{
            
            read_char(position_code, 'O');
            draw_grid(position_code);
           // check if player O won
           if( check_win(position_code, 'O')==1){
            cout<<"Player O wins!"<<endl;
            break;
           }
        }

    }
     int choice;
     cout<<"Would you like to play another round? (1=yes, 0=no):";
     cin>>choice;

     if (choice==0){
        cout<<"Thanks for playing!"<<endl;
        break;
     }
    }
    return 0;
}


// Draw the tic-tac-toe board
// Pre: the length of the code is 9
// Post: prints the grid to the screen

// Function
void draw_grid(string code){
    cout<<"Current Board: "<<endl;
    cout<<" "<<code[0]<<" | "<<code[1]<<" | "<<code[2]<<endl;
    cout<<"------------"<<endl;
    cout<<" "<<code[3]<<" | "<<code[4]<<" | "<<code[5]<<endl;
    cout<<"------------"<<endl;
    cout<<" "<<code[6]<<" | "<<code[7]<<" | "<<code[8]<<endl;
}

// It will read the player input and place X or O
// Pre: 9 length code
// Post: asks the player for positions (1-9);
void read_char(string &code, char c){
    int position;
    
    
    cout<<"Enter you position: ";
    cin>>position;

    while (position<1 || position>9){
        cout<<"Invalid input. Try again: ";
        cin>>position;
    }
   code[position-1]=c;
}

int check_win(string code, char c){
    
    // will work with X part
    if (code[0]=='X' && code[1]=='X' && code[2]=='X'){
        return 1;
    }
    else if(code[3]=='X'&& code[4]=='X' && code[5]=='X'){
        return 1;
    }
    else if(code[6]=='X' && code[7]=='X' && code[8]=='X'){
        return 1;
    }
    else if(code[0]=='X' && code[3]=='X' && code[6]=='X'){
        return 1;
    }
    else if(code[1]=='X' && code[4]=='X' && code[7]=='X'){
        return 1;
    }
    else if(code[2]=='X' && code[5]=='X' && code[8]=='X'){
        return 1;
    }
    else if(code[0]=='X' && code[4]=='X' && code[8]=='X'){
        return 1;
    }
    else if(code[2]=='X' && code[4]=='X' && code[6]=='X'){
        return 1;
    }

    // will work wil O part
    if (code[0]=='O' && code[1]=='O' && code[2]=='O'){
        return 1;
    }
    else if(code[3]=='O'&& code[4]=='O' && code[5]=='O'){
        return 1;
    }
    else if(code[6]=='O' && code[7]=='O' && code[8]=='O'){
        return 1;
    }
    else if(code[0]=='O' && code[3]=='O' && code[6]=='O'){
        return 1;
    }
    else if(code[1]=='O' && code[4]=='O' && code[7]=='O'){
        return 1;
    }
    else if(code[2]=='O' && code[5]=='O' && code[8]=='O'){
        return 1;
    }
    else if(code[0]=='O' && code[4]=='O' && code[8]=='O'){
        return 1;
    }
    else if(code[2]=='O' && code[4]=='O' && code[6]=='O'){
        return 1;
    }
    else{
        return 0;
    }

}


