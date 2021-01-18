//Description : TUI App for calculate Ohm laws ;
//Created Date: 17/01/2021
//Finshed Date : #! 
//Author : KhaledFathi@protonmail.com
//Language : C 
//Ver : 0.1
//Github repo: https://github.com/khaledfathi/c_practice.git 
//Target : Practice C programming 
//Files :  1/1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

//global var 
char value_1[50] , value_2[50];

//misc _____________________________start
u_int8_t is_number (char *num){
    //check if string number can be convert to int/float or not 
    char allowed []= {'1','2','3','4','5','6','7','8','9','0','.','-'};
    unsigned int  i , j , count=0; 
    u_int8_t dot_flag=0 , minus_flag=0;
    
    for (i=0 ; i<strlen(num) ; i++){
        if (num[i]=='.')dot_flag++;
        if (num[i]=='-')minus_flag++;
        for (j=0 ; j<strlen(allowed); j++){
            if (num[i] == allowed[j]){
                count++; 
            }
        }
    }
    if (dot_flag > 1 || minus_flag > 1 || (num[0]!='-' && minus_flag==1)){
        return 0; 
    }
    if (count == strlen(num)){
        return 1 ; 
    }else {
        return 0 ; 
    }
}

u_int8_t quit (){
    char out[10] ; 
    printf("\nAny key for Quit , Enter to Continue : ");
    fgets(out , 100 , stdin);// repeated two time cuz it catch the first Enter press
    fgets(out , 100 , stdin);
    if (out[0] == 0x0A){ //0x0A = Enter key in ASCII Table
        return 0; 
    }else{
        return 1; 
    }
}

void selection_error (){
    printf("\nERROR : Invalid Selection!\n\n");
    sleep(1);//make delay (1 sec)to see error before continue 
}

void app_interface (char *title , char *ui_text ,  void (*fun1)() , void (*fun2)() , void (*fun3)()){
    char select [2] ;
    select[1] = '\0';
    while (1){
        printf("\n\n### %s ###\n\n", title );
        printf("%s" , ui_text);
        scanf("%s" , select); 
        if (select[1]){
            selection_error(); 
            continue ; 
        }
        if(select[0] == '1'){
            (*fun1)();
        }else if (select[0] == '2'){
            (*fun2)();
        }else if (select[0] == '3'){
            (*fun3)();
        }else if (select[0] == 'q' || select[0] == 'Q'){
            break; 
        }else {
            selection_error(); 
            continue ; 
        }
    }
}
//misc _____________________________end


//calculations app ________________________start

//general form function 
u_int8_t input_form (char *text_1 , char *text_2){
   printf("\n%s" , text_1);
   scanf("%s", value_1);
   printf("%s" , text_2);
   scanf("%s" , value_2);
   if (is_number(value_1) && is_number(value_2)){
       return 1; 
   }else {
       return 0; 
   }
   
}

/*########## Resistance Calculations ###########*/
void resistance_v_i(){
    while (1){
        if ( input_form("Volt : " , "Current : ") ){
            if (atof(value_2) != 0){//avoid math error [divide by zero]
                printf("\n### Resistance = %.3f Ohm ###\n", atof(value_1)/atof(value_2) );
            }else {
            printf("\nERROR : Current Can't be Zero!\n");
            }
        }else {
            printf("\nERROR : Enter Numbers Only!\n");
        };
        if (quit())break;
    }
}

void resistance_v_p(){
    while (1){
       if (input_form("Volt : " , "Power : ") ){
            if (atof(value_2) != 0){//avoid math error [divide by zero]
                printf("\n### Resistance = %.3f Ohm ###\n", (atof(value_1)*atof(value_1))/atof(value_2) );
            }else {
            printf("\nERROR : Power Can't be Zero!\n");
            }
        }else {
            printf("\nERROR : Enter Numbers Only!\n");
        };
        if (quit())break;
    }
}

void resistance_p_i(){
    while (1){
        if ( input_form("power : " , "Current : ") ){
            if (atof(value_2) != 0){//avoid math error [divide by zero]
                printf("\n### Resistance = %.3f Ohm ###\n", atof(value_1)/( atof(value_2)*atof(value_2) ) );
            }else {
            printf("\nERROR : Current Can't be Zero!\n");
            }
        }else {
            printf("\nERROR : Enter Numbers Only!\n");
        };
        if (quit())break;
    }
}

/*########## END Resistance Calculations ###########*/

/*########## Voltage Calculations ###########*/
void voltage_r_i(){
    while (1){
        if ( input_form("power : " , "Current : ") ){
            printf("\n### Voltage = %.3f Volt ###\n", atof(value_1)*atof(value_2) );
        }else {
            printf("\nERROR : Enter Numbers Only!\n");
        };
        if (quit())break;
    }
}

void voltage_r_p(){
    while (1){
        if ( input_form("Resistance : " , "Power : ") ){
              printf("\n### Voltage = %.3f Volt ###\n", sqrt(atof(value_1))*atof(value_2) );
        }else {
            printf("\nERROR : Enter Numbers Only!\n");
        };
        if (quit())break;
    }
}
void voltage_p_i(){
    while (1){
        if ( input_form("power : " , "Current : ") ){
            if (atof(value_2) != 0){//avoid math error [divide by zero]
                printf("\n### Voltage = %.3f Volt ###\n", atof(value_1)/atof(value_2)  );
            }else {
            printf("\nERROR : Current Can't be Zero!\n");
            }
        }else {
            printf("\nERROR : Enter Numbers Only!\n");
        };
        if (quit())break;
    }
}
/*########## END Voltage Calculations ###########*/

/*########## Current Calculations ###########*/
void current_v_r(){
    while (1){
        if ( input_form("Volt : " , "Current : ") ){
            if (atof(value_2) != 0){//avoid math error [divide by zero]
                printf("\n### Current = %.3f Amp ###\n", atof(value_1)/atof(value_2)  );
            }else {
            printf("\nERROR : Current Can't be Zero!\n");
            }
        }else {
            printf("\nERROR : Enter Numbers Only!\n");
        };
        if (quit())break;
    }
}
void current_v_p(){
    while (1){
        if ( input_form("Volt : " , "Power : ") ){
            if (atof(value_1) != 0){//avoid math error [divide by zero]
                printf("\n### Current = %.3f Amp ###\n", atof(value_2)/atof(value_1)  );
            }else {
            printf("\nERROR : Voltage Can't be Zero!\n");
            }
        }else {
            printf("\nERROR : Enter Numbers Only!\n");
        };
        if (quit())break;
    }
}
void current_p_r(){
    while (1){
        if ( input_form("Power : " , "Resistance : ") ){
            if (atof(value_2) != 0){//avoid math error [divide by zero]
                printf("\n### Current = %.3f Amp ###\n", sqrt(atof(value_1)/atof(value_2)) );
            }else {
            printf("\nERROR : Resistance Can't be Zero!\n");
            }
        }else {
            printf("\nERROR : Enter Numbers Only!\n");
        };
        if (quit())break;
    }
}
/*########## END Current Calculations ###########*/

/*########## Power Calculations ###########*/
void power_v_r(){
    while (1){
        if ( input_form("Volt : " , "Current : ") ){
            if (atof(value_2) != 0){//avoid math error [divide by zero]
                printf("\n### Current = %.3f Amp ###\n", (atof(value_1)*atof(value_1))/atof(value_2)  );
            }else {
            printf("\nERROR : Resistance Can't be Zero!\n");
            }
        }else {
            printf("\nERROR : Enter Numbers Only!\n");
        };
        if (quit())break;
    }
}
void power_i_r(){
    while (1){
        if ( input_form("Volt : " , "Power : ") ){
            printf("\n### Current = %.3f Amp ###\n", (atof(value_1)*atof(value_1))*atof(value_2) );
        }else {
            printf("\nERROR : Enter Numbers Only!\n");
        };
        if (quit())break;
    }
}
void power_v_i(){
    while (1){
        if ( input_form("Power : " , "Resistance : ") ){
            printf("\n### Current = %.3f Amp ###\n", atof(value_1)*atof(value_2)) ;
        }else {
            printf("\nERROR : Enter Numbers Only!\n");
        };
        if (quit())break;
    }
}
/*########## END Power Calculations ###########*/

//calculations app ________________________end

//apps entry_________________start 
void resistance_app (){
    char ui_text[] = "1- By Voltage and Current\n2- By Voltage and Power\n3- By Power and Current\nQ- For quit\n>>> ";
    app_interface("RESISTANCE" , ui_text , &resistance_v_i , &resistance_v_p , &resistance_p_i); 
}

void voltage_app (){
    char ui_text[] = "1- By Resistance and Current\n2- By Resistance and Power\n3- By Power and Current\nQ- For quit\n>>> ";
    app_interface("VOLTAGE" , ui_text , &voltage_r_i , &voltage_r_p , &voltage_p_i); 
}

void current_app (){
    char ui_text[] = "1- By Voltage and Resistance\n2- By Voltage and Power\n3- By Power and Resistance\nQ- For quit\n>>> ";
    app_interface("CURRENT" , ui_text , &current_v_r , &current_v_p , &current_p_r); 
}

void power_app(){
    char ui_text[] = "1- By Voltage and Resistance\n2- By Current and Resistance\n3- By Voltage and Current\nQ- For quit\n>>> ";
    app_interface("POWER" , ui_text , &current_v_r , &current_v_p , &current_p_r); 
}
//apps entry_________________end 


//######## MAIN ############
int main (){
    char select[2];
    select[1] ='\0'; 
    while (1){
    printf("\n\n### Main Menu ###\n\n");
    printf("\n1- Get Resistance \n2- Get Voltage\n3- Get Current\n4- Get Power\nQ- for quit\n>>> ");
        scanf("%s" , select );
        if (select[1]){
            selection_error();
            continue ; 
        };
        if (select[0] == '1'){
            printf("Option resistance\n"); //Coding Here 
            resistance_app(); 
        }else if(select[0] == '2'){
            voltage_app();
        }else if(select[0] == '3'){
            current_app(); 
        }else if (select[0] == '4'){
            power_app();
        }else if (select[0] == 'Q' || select[0] == 'q'){
            break; 
        }else{
            selection_error();
            continue;
        }
    }
    return 0 ; 
}
/*################# END OF FILE #############*/


