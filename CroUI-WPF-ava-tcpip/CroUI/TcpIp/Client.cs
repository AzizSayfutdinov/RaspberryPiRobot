using System;
using System.Text;
using System.Net;
using System.Net.Sockets;

namespace CroUI.TcpIp
{
    public class Client
    {
        private byte[] rcvData = new byte[256];
        private byte[] sendData = new byte[128];
        IPEndPoint ipEndPoint;
        Socket server;

        public Client()
        {
            string ipEth = "192.168.1.2";
            string ipWln = "10.0.0.7";

            ipEndPoint = new IPEndPoint(IPAddress.Parse(ipEth), 54000);
            server = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            connect();

            string input = "Hi Server";
            server.Send(Encoding.ASCII.GetBytes(input));
        }

        public void connect()
        {
           try
            {
                server.Connect(ipEndPoint);
            } catch(SocketException socketEx)
            {
                // ToDo
            }

            byte[] succ = BitConverter.GetBytes('x');

        }

        public void send(byte[] command)
        {
            try
            {
                server.Send(command);
            } catch(SocketException socketEx)
            {
                // ToDo
            } catch(Exception ex)
            {
                // ToDo
            }
        }
    }
}
