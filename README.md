## Introduction
These are space shooting games using Allegro5. If you want to play 1v1 space shooting game, you can check those folders named 1v1_\*\*, which depends on the operating system you're using. If you want to play 2v2 space shooting game, you can check those folders named 2v2_\*\*.

Our inspiration came from https://kickingbrains.wordpress.com/2016/08/03/space-shooter-a-simple-c-game-for-windows/, but since the game in it is a single-player game, and it can only run on Windows, so we learned how to use Allegro5 library and designed new elements into the game to make it more colorful and interesting.

Below is the introduction of all the files.

## source.cpp
This file is the code from https://kickingbrains.wordpress.com/2016/08/03/space-shooter-a-simple-c-game-for-windows/ 

This is a single-player game running on Windows. You can use the arrow keys to move the spaceship, and press the space bar to attack.

You'll get 10 points if you successfully attack an asteroid. You'll win if you get 100 points; If you get hit by an asteroid, your heart or energy will decrease by 1. You'll lose if you lose all your hearts.

## hw.cpp
This file is modified from source.cpp. This is an 1v1 space shooting game demo (also an early version of our project), which can run on all operating systems. If you run hw.cpp, you'll see an automatic space shooting battle on terminal.

## 1v1_\*\*
#### Introduction
This is an 1v1 space shooting game. Two players should try their best to attack, defend, and survive. The player who survives longer wins.
#### How to run it
1. Download the environment
    - Windows :
        - No need to do anything
    - Linux :
    ```
    sudo apt-get install make g++
    sudo add-apt-repository ppa:allegro/5.2
    sudo apt-get install liballegro*5.2 liballegro*5-dev 
    ```
    - MacOS : 
    ```
    brew install allegro
    brew install pkg-config
    ```
2. Change directory into the correct folder
    - Windows : ``` cd 1v1_windows ```
    - Linux : ``` cd 1v1_linux ```
    - MacOS :  ``` cd 1v1_mac ```

3. Compile the game
    - Windows : ``` ./build.bat ```
    - Linux : ``` make ```
    - MacOS :  ``` make ```

4. Run the game
    - Windows : ``` ./run.bat ```
    - Linux : ``` ./bin/main ```
    - MacOS :  ``` ./bin/main ```

#### How to play
- How to win : Defeat your opponent and survive longer than him.
- Player1 : Press WASD to move, and press space bar to attack. 
- Player2 :  Press arrow keys to move, and press Enter to attack.
- Parameters of players:
    - HP : 100 in the beginning. If it becomes 0 or negative, you lose.
    - bullet_power : If you bullet hits your opponents, his HP will decrease by your bullet_power.
    - exp : 0 in the beginning. If your bullet hits an asteroid, it increase by 20. Your bullet power will increase by 1 if your exp is exactly 100.
    - energy : Every time you attack, you should spend 20 energy. Energy keeps increasing every ticks if it's lower than 100.
- About asteroids : Asteroids will be randomly generated and fly into the map. 
- About potions: If you touch a potion, you will get some buff.
    - Red potion : HP + 30
    - Purple potion : bullet power + 1
    - Green potion : Energy gets full

## 2v2_\*\*
#### Introduction
This is an 2v2 space shooting game. Players should try their best to attack, defend, and survive. The team which survives longer wins.

Since it may be difficult for four people to play the game, using the same keyboard simultaneously, so I modified this into a single-player game. The other three players are AIs, and you should collaborate with your teammate AI to defeat both your opponents.

#### How to run it
1. Download the environment
    - Windows :
        - No need to do anything
    - Linux :
    ```
    sudo apt-get install make g++
    sudo add-apt-repository ppa:allegro/5.2
    sudo apt-get install liballegro*5.2 liballegro*5-dev 
    ```
    - MacOS : 
    ```
    brew install allegro
    brew install pkg-config
    ```
2. Change directory into the correct folder
    - Windows : ``` cd 2v2_windows ```
    - Linux : ``` cd 2v2_linux ```
    - MacOS :  ``` cd 2v2_mac ```

3. Compile the game
    - Windows : ``` ./build.bat ```
    - Linux : ``` make ```
    - MacOS :  ``` make ```

4. Run the game
    - Windows : ``` ./run.bat ```
    - Linux : ``` ./bin/main ```
    - MacOS :  ``` ./bin/main ```

#### How to play
- How to win : Defeat both your opponents and survive longer than them.
- Player : Press WASD to move, and press space bar to attack. 
- Parameters of players : Same as the parameters in 1v1 games.
- About asteroids : Asteroids will be randomly generated and fly into the map. 
- About potions: If you touch a potion, you will get some buff.
    - Red potion : HP + 30
    - Purple potion : bullet power + 1
    - Green potion : Energy gets full
    - Dark Blue potion : invincible for a while
    - White potion : double bullet_power for a while
    - Yellow potion : exp added plus 10 when bullet hits an asteroid
    - Light Blue potion : energy needed -5 when attacking
