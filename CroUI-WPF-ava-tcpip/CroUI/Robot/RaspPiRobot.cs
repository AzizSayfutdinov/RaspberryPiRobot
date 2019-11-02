using CroUI.TcpIp;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CroUI.Robot
{
    public class RaspPiRobot
    {
        public int Speed { get; set; }
        Client client;

        public RaspPiRobot()
        {
            client = new Client(); 
        }

        public void move(int speed)
        {
            Speed = speed;
            if(speed > 0)
            {
                sendStatusMessage('f');
            } else if(speed < 0)
            {
                sendStatusMessage('b');
            } else
            {
                sendStatusMessage('s');
            }
        }

        public void turnLeft()
        {
            sendStatusMessage('l');
        }

        public void turnRight()
        {
            sendStatusMessage('r');
        }

        public void alignNorth()
        {
            // odometry.align()
            sendStatusMessage('a');
        }

        public void sendStatusMessage(char cmd)
        {
            client.send(BitConverter.GetBytes(cmd));
        }
    }
}
