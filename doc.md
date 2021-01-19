# Descripe Functions on Main File . 

---
---

**file Name:** *app.c*

---

***is_number(char \*num)***

*descreption :* 
- check if string can be convert to number or not.
- return 0\|1

*parameter :*

- (char \*num)  accept number as string 

---
***quit()***

*descreption :* 
- print interface fot user to 'Quit' or 'Continue'
- catch Enter key or other character 
- return 0\|1
---
***selection_error()***

*descreption :* 
- print Error Message then make delay for 1 sec 
---
***resistance_app()***

***voltage_app()***

***current_app()***

***power_app()***

*description :*
- all functions have same structure. 
- initialize the titles and selection form for 1 of 4 apps (Resistance , Voltage , Current , Power) .
- redirect to specific app interface .
---
***app_interface (char \*title , char \*ui_text ,  void (\*fun1)() , void (\*fun2)() , void (\*fun3)() )***

*description :*
- Build Selection form for specific app (Resistance , Voltage , Current , Power) 
- create title(text name) and selection form for specific app as a user interface 
- redirect each selection to specific function to make user input values and do calculation then show results 

*parameter :*
- (char \*title) : text for title | string 
- (char \*ui_text) : text for selection form | string 
- ( void (\*fun1)() )   , ( void (\*fun2)()i )  ,  ( void (\*fun)() ) : pass function depend on selected app to run calculation 
---
***input_form(char \*text_1 , char \*text_2)***

*description :*
- build  user input form , to input 1st value and 2nd value 
- save values to globale varibale for next calculation 
- check if this number can be calculate or no 
- return 0/|1

*parameter :*
- (char \*text_1) : 1st value for calculation 
- (char \*text_2) : 2nd value for calculation 
---
**NOTE** : v , i , r , p in functions names stand for [in order] voltage , current , Resistance , Power

***resistance_v_i() , resistance_v_p() , resistance_p_i()***

*description :*
- run calculation and print results for resistance app
---
***voltage_r_i() , voltage_r_p() , voltage_p_i()***

*description :*
- run calculation and print results for resistance app 
---
***current_v_r() , current_v_p() , current_p_r()***

*description :*
- run calculation and print results for resistance app 
---
***power_v_r() , power_i_r() , power_v_i()***

*description :*
- run calculation and print results for resistance app 


