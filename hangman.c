#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

/* TODO: complete the definition of the possible_words[] array. 
*  You may populate it however you'd like.
*  Make sure to update the macro for NUM_WORDS to match the length of your
*  possible words array.
*/
// defining a macro
#define NUM_WORDS 11
// defining a pointer to our word bank
char* possible_words[11] = {"hello", "world", "strawberry", "orange", "dinosaur", "apocalypse", "twilight", "fiddle", "bear", "awkward", "bagpipes"};

// random number generator
int random_number(int min_num, int max_num) {
        srand(time(NULL));
        return (rand() % (max_num - min_num)) + min_num;
}

/* Populates the given display string buffer with '_' characters
 * corresponding to the length of the answer string.
 * For example: if length == 3, after running generate_display_string
 * the display string buffer will contain {'_', '_' , '_','\0'}
*/
void generate_display_string(char* display_string, int length) {
  int i = 0;
  for (i = 0; i < length; i++){
    display_string[i] = '_';
  }
  display_string[length] = '\0';
}

/* Updates the display string to reveal any correctly guessed characters.
 * Also updates value of letters_remaining with the remaining numbers of letters to guess.
 * For example: if answer_string is "hello", and guess is 'l', display string is "_____",
 * update the display string to "__ll_" and value of letters_remaining to 3.
*/
void update_display_string(char* display_string, char* answer_string, char guess, int* letters_remaining) {
  int length = strlen(answer_string);
  for (int i = 0; i < length; i++){
      if (answer_string[i] == guess && display_string[i] == '_'){
	display_string[i] = guess;
	(*letters_remaining)--;
      }
  }
}


/* Returns true (1) if guess character is in answer_string 
*/
_Bool guess_in_answer(char* answer_string, char guess){
  int i = 0;
  for (i = 0; answer_string[i] != '\0'; i++){
    if (answer_string[i] == guess){
      return 1;
    }
  }
  return 0;
}

int main(void) {
    char display_string_buffer[100]; // space for our display string
    
    int lives = 3;

    int random_index = random_number(0, NUM_WORDS);
    char* answer = possible_words[random_index];

    // Variable storing the letters left to guess
    int letters_to_guess = strlen(answer);
    generate_display_string(display_string_buffer, letters_to_guess);

    /* TODO: update the game logic to stop when you either lose/win */
     while(1) {

        // print number of lives left and space-seperated display_string
        printf("LIVES: %d\n", lives);
        for(int i = 0; i < strlen(answer); i++) {
            printf("%c ", display_string_buffer[i]);
        }
        printf("\n");

        // scan the single-character user guess from STDIN into the variable guess
        printf("Guess: ");
        char guess;
        scanf(" %c", &guess); 

        /* 
        TODO:
        Call guess_in_answer and decrement lives if the guess is incorrect, 
        update display string otherwise.
        */

	if (guess_in_answer(answer, guess)){
	  update_display_string(display_string_buffer, answer, guess, &letters_to_guess);
	  if (letters_to_guess == 0){
	    printf("you win!! nice job");
	    break;
	  }
	} else {
	  lives--;
	  if (lives == 0){
	    printf("you lost... try again!");
	    break;
	  }  
	}
    }

    /* TODO: print win/lose message */


}
