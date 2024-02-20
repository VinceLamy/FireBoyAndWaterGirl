#include <iostream>
#include <string>
#include <algorithm>

#include "json.hpp"
#include "serial/SerialPort.hpp"

using json = nlohmann::json;
SerialPort* arduino;

#define BAUD 256000
#define MSG_MAX_SIZE 512

bool SendToSerial(SerialPort *arduino, json j_msg){
    // Return 0 if error
    std::string msg = j_msg.dump();
    bool ret = arduino->writeSerialPort(msg.c_str(), msg.length());
    return ret;
}

bool RcvFromSerial(SerialPort *arduino, std::string &msg){
    // Return 0 if error
    // Message output in msg
    std::string str_buffer;
    char char_buffer[MSG_MAX_SIZE];
    int buffer_size;

    msg.clear(); // clear string

    buffer_size = arduino->readSerialPort(char_buffer, MSG_MAX_SIZE);
    str_buffer.assign(char_buffer, buffer_size);
    msg.append(str_buffer);

    msg.pop_back(); //remove '/n' from string

    return true;
}

int main()
{
    std::string port = "COM4";

    arduino = new SerialPort(port.c_str(), BAUD);
    if (!arduino->isConnected())
    {
        std::cerr << "Impossible de se connecter au port "<< std::string(port) <<". Fermeture du programme!" << std::endl;
        exit(1);
    }


    int etat_joueur = 0;
    std::string msg;
    json rcv_msg, send_msg;
    
    while (true)
    {
        rcv_msg.clear();

        if (!RcvFromSerial(arduino, msg))
        {
            std::cout << "Erreur lecture port serie" << std::endl;
        }

        if (msg.size() > 0)
        {
            msg.erase(std::remove(msg.begin(), msg.end(), '\n'), msg.end());
            if (msg.size() == 125)
            {
                rcv_msg = json::parse(msg);
                std::cout << rcv_msg << std::endl;
            }
        }

        if (rcv_msg["boutons"][0]["1"] == 1 )
        {
            if (etat_joueur == 0)
            {
                send_msg["joueur"] = 1;
                etat_joueur = 1;
            }
            else if (etat_joueur == 1)
            {
                send_msg["joueur"] = 2;
                etat_joueur = 0;
            }
        }
        

        send_msg["seg1"] = 0;
        send_msg["seg2"] = 0;
        send_msg["lcd"] = "Hi!";

        SendToSerial(arduino, send_msg);

        Sleep(15);
    }

    arduino->closeSerial();
}