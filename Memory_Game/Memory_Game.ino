/**************************************************************************/
/* 
   @file     Memry_Game.ino
   @author   Ryan Walker (University of Waterloo)
   @license  BSD (see README.md)
   
   Simple application for teaching basic circuit design and microcontroller 
   capabilities. Includes setup mode operation, and a memory game with 
   coloured LEDs and audio output.
*/
/**************************************************************************/

// Defining the pin mapping for the various functions
#define BUTTON_1       P2_0
#define BUTTON_2       P2_1
#define BUTTON_3       P2_2
#define BUTTON_4       P2_3
#define SWITCH         P1_3
#define LED_1          P1_4
#define LED_2          P1_5
#define LED_3          P1_7
#define LED_4          P2_4
#define SPEAKER        P1_6
#define RANDOM_SEED    A1


// Global Variables
uint8_t sequence[50], player_input[50], highscore[50];
uint8_t game_level, highscore_level;
uint16_t game_speed, input_speed;

// Setup and initialize microcontroller functionality (this function runs once at startup)
void setup() {
   
  // Allows serial communication to terminal over USB (not used for this project)
  Serial.begin(9600);

  // Setup the 4 game LEDs as outputs
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);  
  
  // Setup the speaker as an output
  pinMode(SPEAKER, OUTPUT);
 
  // Setup the 4 games buttons, and program switch as inputs
  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);
  pinMode(BUTTON_3, INPUT_PULLUP);
  pinMode(BUTTON_4, INPUT_PULLUP);
  pinMode(SWITCH, INPUT_PULLUP);
   
  // Setup Pin 1.1 as an analog input for randon number generator seed
  pinMode(RANDOM_SEED, INPUT);
 
  // Generate the Random Sequence
  randomSeed(analogRead(RANDOM_SEED));
  for (int i=0; i<=50; i++){
    sequence[i] = random(1, 5);
  }
 
  //Initialize LEDs in the OFF state
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, LOW);
  digitalWrite(LED_3, LOW);
  digitalWrite(LED_4, LOW);
 
  // Initial Game State
  highscore_level = 0;    // Reset the highscore keeper to zero
  game_level = 0;         // Reset the current game level to zero
  game_speed = 500;       // Set the speed of the game sequence to 500 milliseconds
  input_speed = 500;      // Set the input speed to 500 milliseconds
  
  // Run a brief LED and sound sequence to indicate the program has started
  program_init_sequence();  
  
  // -------------------------- Assembly Verification --------------------------- //
  //
  // This section of code is used to check functionality of the circuit during the
  // assembly procedure.  It is intended solely as a teaching tool and has no effect
  // on game play.  The 'Assembly Verification' secion can be deleted if only game
  // play is desired and this game will still function correctly.
  
  // When a button is pressed, turn on corresponding LED and play a tone
  while(1)
  {  
    // When S2 is pressed, exit 'Assembly Verification' mode and start gameplay
    if (digitalRead(SWITCH) == LOW)
    {
      break;
    }
    else if (digitalRead(BUTTON_1) == LOW)
    {      
      play(1, input_speed);  
    }
    else if (digitalRead(BUTTON_2) == LOW)
    {
      play(2,input_speed); 
    }
    else if (digitalRead(BUTTON_3) == LOW)
    {
      play(3,input_speed);
    }
    else if (digitalRead(BUTTON_4) == LOW)
    {
      play(4,input_speed);
    }
      
  }
  
  // ------------------------ Assembly Verification End-------------------------- //
  
   // Play the Game Intro Sequence of lights and sound
   game_start_sequence();  
}


// The main loop for the program.  This section of code repeats as long as the device
// is powered up.
void loop()
{  
  
  // --------------------------------- Gameplay --------------------------------- //
  
  // Play the game sequence
  for (int j=0; j<=game_level; j++)
  {
    play(sequence[j], game_speed);
  }

  // Get input sequence from the user
  for (int i=0; i<=game_level; i++)
  {
    while(1)
    {
      if (digitalRead(BUTTON_1) == LOW)
      {
        player_input[i] = 1;
        play(1, input_speed);  
        break;
      }
     else if (digitalRead(BUTTON_2) == LOW)
     {
        player_input[i] = 2;
        play(2,input_speed); 
        break;
      }
      else if (digitalRead(BUTTON_3) == LOW)
      {
        player_input[i] = 3;
        play(3,input_speed);
        break;
      }
      else if (digitalRead(BUTTON_4) == LOW)
      {
        player_input[i] = 4;
        play(4,input_speed);
        break;
      }
    
      if (digitalRead(SWITCH) == LOW)
      {
        high_score_playback(200);
      }
    }
  
    // Check if the input matches the sequence
    if (player_input[i] != sequence[i])            // If incorrect
    {
      if (game_level > highscore_level)            // Check for highscore
      {
        highscore_level = game_level;
        for (int h=0; h<highscore_level; h++)    
        {
          highscore[h] = sequence[h];              // Save highscore
         }
       }
      you_lose();                                  // Play losing tone
      game_level = -1;                             // Reset game level
      delay(1000);
      break;
    }
 
  }

  // Increment game level
  game_level++;                        
  delay(500);
  
}

// A sequence of LED flashes and tones to indicate the program has started
void program_init_sequence()
{
  for (int i=0; i<1; i++){
    digitalWrite(LED_4, LOW);
    digitalWrite(LED_1, HIGH);
    delay(100);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_1, HIGH);
    delay(100);
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, HIGH);
    delay(100);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, HIGH);
    delay(100);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, HIGH);
    delay(100);
  } 
  digitalWrite(LED_4, LOW);
  tone(SPEAKER, 1976);
  delay(60);
  noTone(SPEAKER);
  delay(1);
  tone(SPEAKER, 2637);
  delay(360);
  noTone(SPEAKER);
  delay(1000); 
}


// A sequence of LED flashes and tones to indicate gameplay mode as started
void game_start_sequence()
{
  for (int i=0; i<1; i++){
    digitalWrite(LED_4, LOW);
    digitalWrite(LED_1, HIGH);
    delay(100);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_1, HIGH);
    delay(100);
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, HIGH);
    delay(100);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, HIGH);
    delay(100);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, HIGH);
    delay(100);
  } 
  digitalWrite(LED_4, LOW);
  tone(SPEAKER, 1319);
  delay(120);
  noTone(SPEAKER);
  delay(10);
  
  tone(SPEAKER, 1568);
  delay(120);
  noTone(SPEAKER);
  delay(10);
  
  tone(SPEAKER, 2637);
  delay(120);
  noTone(SPEAKER);
  delay(10);
  
  tone(SPEAKER, 2093);
  delay(120);
  noTone(SPEAKER);
  delay(10);
  
  tone(SPEAKER, 2349);
  delay(120);
  noTone(SPEAKER);
  delay(10);
  
  tone(SPEAKER, 3136);
  delay(120);
  noTone(SPEAKER);
  delay(1000); 
}


// Function used to control LEDs and play tones for each button press
void play(uint8_t button, unsigned int duration)
{
  switch (button) {
    case 1:
      digitalWrite(LED_1, HIGH);
      tone(SPEAKER, 415);
      delay(duration);
      digitalWrite(LED_1, LOW);
      noTone(SPEAKER);
      break;
    case 2:
      digitalWrite(LED_2, HIGH);
      tone(SPEAKER, 310);
      delay(duration);
      digitalWrite(LED_2, LOW);
      noTone(SPEAKER);
      break;
    case 3:
      digitalWrite(LED_3, HIGH);
      tone(SPEAKER, 252);
      delay(duration);
      digitalWrite(LED_3, LOW);
      noTone(SPEAKER);
      break;
    case 4:
      digitalWrite(LED_4, HIGH);
      tone(SPEAKER, 209);
      delay(duration);
      digitalWrite(LED_4, LOW);
      noTone(SPEAKER);
      break;
    default:
      noTone(SPEAKER);
  }
}
  
  
// Function for handling losing  
void you_lose()
{
  // Play losing tone
  tone(SPEAKER, 42);          
  delay(1000);
  noTone(SPEAKER);
  
  // Generate new Random Sequence for next game
  for (int a=0; a<=50; a++){
    sequence[a] = random(1, 5);
  }
}


// Function that plays back the current highscore at a faster rate
void high_score_playback(unsigned int playback_speed)
{
 for (int h=0; h<highscore_level; h++)
 {
  play(highscore[h], playback_speed);
 }
}
