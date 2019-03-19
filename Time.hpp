//
// Created by reyha on 20/03/2019.
//

#ifndef ENGISFARM_TIME_HPP
#define ENGISFARM_TIME_HPP

// Kelas Time adalah blueprint dari objek yang menentukan waktu pada permainan
class Time {
private:
    static int gameTime;               // Menampung game time dalam satuan tick
public:
    static void advanceGameTime();     // Menambah 1 tick pada game time
    static int getGameTime();    // Getter gameTime
};


#endif //ENGISFARM_TIME_HPP
