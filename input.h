/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \param attemps Cantidad de intentos permitidos
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getInt(int* input, char message[], char eMessage[], int lowLimit, int hiLimit, int attemps);

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \param attemps Cantidad de intentos permitidos
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getFloat(float* input, char message[], char eMessage[], float lowLimit, float hiLimit, int attemps);

/**
* \brief Solicita un caracter al usuario y lo valida
* \param input Se carga el caracter ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \param attemps Cantidad de intentos permitidos
* \return Si obtuvo el caracter [0] si no [-1]
*
*/
int getChar(char* input, char message[], char eMessage[], char lowLimit, char hiLimit, int attemps);

/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \param attemps Cantidad de intentos permitidos
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getString(char* input, char message[], char eMessage[], int lowLimit, int hiLimit, int attemps);

/**
* \brief Solicita genero [F][M] y lo valida
* \param input Se carga el caracter ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param attemps Cantidad de intentos permitidos
* \return Si obtuvo el genero [0] si no [-1]
*
*/
int getGender(char* input, char message[], char eMessage[], int attemps);
