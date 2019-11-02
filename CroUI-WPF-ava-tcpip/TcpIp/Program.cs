using CroUI.TcpIp.Server;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TcpIp
{
    class Program
    {
        static void Main(string[] args)
        {
            var piServer = new PiTcpServer();
            piServer.StartServer();
        }
    }
}
