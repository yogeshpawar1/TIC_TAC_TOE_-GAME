#include<iostream>
#include<list>
#include<cstdlib>
#include<algorithm>
#include<ctime>
using namespace std;

void draw(char arr[3][3]){                    ////DRAW THE DIAGRAM 
cout<<"|----+----+----+----+----+---+|"<<endl;
for(int i=0;i<3;i++){
    cout<<"|         |         |         |"<<endl;
    for(int j=0;j<3;j++){       
        cout<<"|     "<<arr[i][j]<<"   ";
    }
    cout<<"|"<<endl<<"|         |         |         |"<<endl;
    cout<<"|----+----+----+----+----+---+|"<<endl;  
}
}

int randomvariable(){                 // RANDOM VARIABLE GENRATOR
    int min=1,max=9;
    int ranf=min+(rand()%(max-min+1));
    return ranf;
}
list<int> element_check(char arr[3][3]){                   ///CHECK WHICH ELEMENT SPACE IS LEFT
    list<int>listsof_elements;
    int cou=0;
    for(int i=0;i<3;i++){       
        for(int j=0;j<3;j++){
             cou++;
            if(arr[i][j]=='X'||arr[i][j]=='0') continue;
            listsof_elements.push_back(cou);
        }
    }
    return listsof_elements;
}

void set_variable(char arr[3][3],int valueset_at,char which_value){                       //SET TTHE ELEMENT 
    char at = valueset_at+'0';
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(arr[i][j]==at){arr[i][j]=which_value;return;}

        }
    }
}



// char win_check(char arr[3][3]){
//     char t;
//     if(arr[0][0]== '0'&& arr[0][1]=='0'&& arr[0][2]=='0') t='W';return t; 
//     if(arr[1][0]== '0'&& arr[1][1]=='0'&& arr[1][2]=='0') t='W';return t; 
//     if(arr[2][0]== '0'&& arr[2][1]=='0'&& arr[2][2]=='0') t='W';return t; 
//     if(arr[0][0]== '0'&& arr[1][0]=='0'&& arr[2][0]=='0') t='W';return t; 
//     if(arr[0][1]== '0'&& arr[1][1]=='0'&& arr[2][1]=='0') t='W';return t; 
//     if(arr[0][2]== '0'&& arr[1][2]=='0'&& arr[2][2]=='0') t='W';return t; 

//      if(arr[0][0]== 'X'&& arr[0][1]=='X'&& arr[0][2]=='X') t='L';return t; 
//     if(arr[1][0]== 'X'&& arr[1][1]=='X'&& arr[1][2]=='X') t='L';return t; 
//     if(arr[2][0]== 'X'&& arr[2][1]=='X'&& arr[2][2]=='X') t='L';return t; 
//     if(arr[0][0]== 'X'&& arr[1][0]=='X'&& arr[2][0]=='X') t='L';return t; 
//     if(arr[0][1]== 'X'&& arr[1][1]=='X'&& arr[2][1]=='X') t='L';return t; 
//     if(arr[0][2]== 'X'&& arr[1][2]=='X'&& arr[2][2]=='X') t='L';return t; 
   
  

// }

char win_check(char arr[3][3]) {
    const char players[] = {'0', 'X'};  // '0' → W, 'X' → L

    for (char p : players) {
        // Check rows and columns
        for (int i = 0; i < 3; ++i) {
            if (arr[i][0] == p && arr[i][1] == p && arr[i][2] == p) return (p == '0') ? 'W' : 'L';
            if (arr[0][i] == p && arr[1][i] == p && arr[2][i] == p) return (p == '0') ? 'W' : 'L';
        }

        // Check diagonals
        if (arr[0][0] == p && arr[1][1] == p && arr[2][2] == p) return (p == '0') ? 'W' : 'L';
        if (arr[0][2] == p && arr[1][1] == p && arr[2][0] == p) return (p == '0') ? 'W' : 'L';
    }

    return 'N';  // No winner
}


int main(){
    char arr[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
     srand(time(nullptr));
    //draw(arr);
    // cout<<"random variable : "<<randomvariable()<<endl;
     //set_variable(arr,9,'x');
     char win='D';
     list<int>listsof_element=element_check(arr);
     bool flag=true;
     set_variable(arr,5,'X');
     listsof_element=element_check(arr);
    while(listsof_element.size()!=0){
        if(flag==true){
             draw(arr);
             again:
             cout<<"enter any number betwee 1 to 9 and present space : ";
             int user_number;
             cin>>user_number;
             auto it_found=find(listsof_element.begin(),listsof_element.end(),user_number);
             if(it_found==listsof_element.end()) goto again;
             else{
                 set_variable(arr,user_number,'0');
                listsof_element=element_check(arr);
                flag=false;
             }

        }
        else{
            aagain:
            int computer =randomvariable();
            auto itt_found=find(listsof_element.begin(),listsof_element.end(),computer);
             if(itt_found==listsof_element.end()) goto aagain;
             else{
                 set_variable(arr,computer,'X');
                listsof_element=element_check(arr);
                flag=true;

             }
           

        }


        win=win_check(arr);
        if(win=='W'|| win=='L'){
            break;
        }

    }
       win=win_check(arr);
       
    if(win=='W') cout<<"won the match: "<<endl;
    else if(win=='L') cout<<"lose the match : "<<endl;
         else cout<<"draw the match : "<<endl;

    draw(arr);





    return 0;
}