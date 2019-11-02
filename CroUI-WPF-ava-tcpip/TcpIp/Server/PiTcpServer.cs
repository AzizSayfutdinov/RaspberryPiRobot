using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;
using System.IO;
using System.Net.Sockets;
using System.Net;
using System.Text;

namespace CroUI.TcpIp.Server
{
    public class PiTcpServer
    {
        private Int32 port;
        private IPAddress ipAddress;
        private TcpListener server;

        public Int32 Port
        {
            get
            {
                return port;
            }
            set
            {
                if (value >= 0)
                    port = value;
            }
        }

        public IPAddress IpAddress
        {
            get
            {
                return ipAddress;
            }
            set
            {
                // for string conversion
                //var rgx = new Regex(@"[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}");
                //if (rgx.Match(value).Success)
                //{
                //    ipAddress = value;
                //}
                ipAddress = value;
            }
        }




        public void StartServer()
        {
            try
            {
                // Set the TcpListener on port 13000.
                port = 9999;
                ipAddress = IPAddress.Parse("127.0.0.1"); // default value
                server = new TcpListener(ipAddress, port);

                // Start listening for client requests.
                server.Start();

                // Buffer for reading data
                Byte[] bytes = new Byte[256];
                String data = null;
                // Enter the listening loop.
                while (true)
                {
                    Console.Write("Waiting for a connection... ");

                    // Perform a blocking call to accept requests.
                    // You could also user server.AcceptSocket() here.
                    TcpClient client = server.AcceptTcpClient();
                    Console.WriteLine("Connected!");

                    data = null;

                    // Get a stream object for reading and writing
                    NetworkStream stream = client.GetStream();

                    int i;

                    // Loop to receive all the data sent by the client.
                    while ((i = stream.Read(bytes, 0, bytes.Length)) != 0)
                    {
                        // Translate data bytes to a ASCII string.
                        data = System.Text.Encoding.ASCII.GetString(bytes, 0, i);
                        Console.WriteLine("Received: {0}", data);

                        // Process the data sent by the client.
                        data = data.ToUpper();

                        byte[] msg = System.Text.Encoding.ASCII.GetBytes(data);

                        // Send back a response.
                        stream.Write(msg, 0, msg.Length);
                        Console.WriteLine("Sent: {0}", data);
                    }

                    // Shutdown and end connection
                    client.Close();
                }
            }
            catch (SocketException e)
            {
                Console.WriteLine("SocketException: {0}", e);
            }
            finally
            {
                // Stop listening for new clients.
                server.Stop();
            }
            Console.WriteLine("\nHit enter to continue...");
            Console.Read();
        }
    }
}

