/*
    Name: Bharath
    Purpose: To create a cross-zero game.
    Date: 16th Sept, 2021

    Approach 1 - Global Variable
    Approach 2 - Local Variable

    TO-DO
        - Validation
            -- Cannot overwrite 'X' or '0' with each other
            -- Row and column values should be between 0-2
*/

// Store cross or zero
char crosszero[3][3];

//Initalize Crosszero matrix. Initally all values are empty
void init() {
    //Go over each row
    for(int i = 0; i<3; i++){
        //Go over each column
        for(int j = 0; j<3; j++){
            //Default value - Space
            crosszero[i][j] = ' ';
        }
    }

}

//Display the cross zero matrix
void display() {
    printf("\n\n Current Matrix:\n");
    for(int i = 0; i<3 ; i++ ){
        //We have to print cross-zero values
        for(int j = 0; j<3; j++) {
            if(j==0 || j==1){
                printf(" %c |",crosszero[i][j]);
            }
            else{
                printf(" %c ",crosszero[i][j]);
            }

        }

        if (i!=2){
             printf("\n---|---|---");
        }
        printf("\n");
    }
}

//Check who is the winner and returns that character, "N" otherwise
char check_winner(){
    char flag_winner = 'N';
    int j;
    //Row-wise winner
    for (int i = 0; i< 3; i++) {
        if(crosszero[i][0] != ' ' && crosszero[i][0] == crosszero[i][1] && crosszero[i][0] == crosszero[i][2]){
            flag_winner = crosszero[i][0];
        }
    }

    //Column-wise winner
    for (j = 0; j< 3; j++) {
        if(crosszero[0][j] != ' ' && crosszero[0][j] == crosszero[1][j] && crosszero[1][j] == crosszero[2][j]){
            flag_winner = crosszero[0][j];
        }
    }

    //Diagonal Winner
    if(crosszero[0][0] != ' ' && crosszero[0][0] == crosszero[1][1] && crosszero[1][1] == crosszero[2][2]){
        flag_winner = crosszero[0][0];
    }
    if(crosszero[2][0] != ' ' && crosszero[2][0] == crosszero[1][1] && crosszero[1][1] == crosszero[0][2]){
        flag_winner = crosszero[2][0];
    }
    return (flag_winner);
}

int display_winner(int iteration){
    char winner;
    int flag = 0;
    winner = check_winner();
    if( iteration == 9 && winner == 'N'){
        printf("\n***********************\nNo winner - Result is Draw.\n***********************\n\n");
    }
    else if (winner=='0' || winner=='X'){
        printf("\n***********************\nHooray! Winner is - '%c'.\n***********************\n\n", winner);
        flag = 1;
    }
    return(flag);
}

// Function to validate input. If the input will overwrite the data or if row/column is not between 0-2 the flag value should be 1

int validate_input(int row, int column){
    int flag=0;
    //Row and column value between 0-2
    if(//YOUR CODE GOES HERE){
        flag = 1;
    }
    //If existing character is not equal to ' '
    if(//YOUR CODE GOES HERE) {
        flag = 1;
    }
    return(flag)
}

//Change this function post writing validation to get new values if row/column values dont match validation rules.
void get_input(int iterator){
    int row, column;
    printf("\nEnter row: ");
    scanf("%d", &row);
    printf("\nEnter column: ");
    scanf("%d", &column);
    if( iterator%2==0){
        crosszero[row][column] = '0';
    }
    else{
        crosszero[row][column] = 'X';
    }

}


int main(){
    int gameover;
    init();
    display();
    for (int i =0; i< 9; i++){
        get_input(i);
        display();
        gameover = display_winner(i);
        if(gameover==1){
            break;
        }
    }
    return(0);
}
