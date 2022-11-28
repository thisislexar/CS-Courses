using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace projectclient
{
    public partial class Form1 : Form
    {

        bool terminating = false;
        bool connected = false;
        Socket clientSocket;
        public Form1()
        {
            Control.CheckForIllegalCrossThreadCalls = false;
            this.FormClosing += new FormClosingEventHandler(Form1_FormClosing);
            InitializeComponent();
        }

        private void ConnectButton_Click(object sender, EventArgs e)
        {

           
            clientSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            string IP = IPBox.Text;

            int portNumber;

            if (Int32.TryParse(PortBox.Text, out portNumber))
            {

                try
                {
                    clientSocket.Connect(IP, portNumber);
                    connected = true;
                    DisconnectButton.Enabled = true;

                    ConnectButton.Enabled = false;

                    RichTextBox.AppendText("Connected!\n");

                    string ClientName = NameBox.Text;

                    Byte[] SendingName = Encoding.Default.GetBytes(ClientName);

                    string sent = Encoding.Default.GetString(SendingName);

                    clientSocket.Send(SendingName);

                    RichTextBox.AppendText("Your client name is: " + ClientName + "\n");

                    Thread receiveThread = new Thread(Receive);
                    receiveThread.Start();

                }
                catch
                {
                    RichTextBox.AppendText("Can not connect!\n");
                }
            }
            else
            {
                RichTextBox.AppendText("Check your port!\n");
            }
        }

        private void Receive()
        {

            while (connected)
            {
                try
                {
                    Byte[] buffer = new Byte[64];

                    clientSocket.Receive(buffer);

                    string incomingQuestion = Encoding.Default.GetString(buffer);

                    RichTextBox.AppendText("Server: " + incomingQuestion + "\n");

                    RichTextBox.AppendText("\n");



                }
                catch
                {
                    if (!terminating)
                    {
                        RichTextBox.AppendText("Disconnected!!\n");
                    }

                    clientSocket.Close();
                    connected = false;
                }

            }
        }

        private void SendButton_Click(object sender, EventArgs e)
        {
            string AnswertoQuestion = AnswerBox.Text;

            Byte[] sendingbuffer = Encoding.Default.GetBytes(AnswertoQuestion);

            string result = Encoding.Default.GetString(sendingbuffer);

            clientSocket.Send(sendingbuffer);

            RichTextBox.AppendText("Your answer to question is " + AnswertoQuestion + "\n");
        }

        private void Form1_FormClosing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            connected = false;
            terminating = true;
            Environment.Exit(0);
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void IPBox_TextChanged(object sender, EventArgs e)
        {

        }

        private void PortBox_TextChanged(object sender, EventArgs e)
        {

        }

        private void NameBox_TextChanged(object sender, EventArgs e)
        {

        }

        private void DisconnectButton_Click(object sender, EventArgs e)
        {
            clientSocket.Close();
            connected = false;
            ConnectButton.Enabled = true;
            
            DisconnectButton.Enabled = false;
        }

        private void RichTextBox_TextChanged(object sender, EventArgs e)
        {

        }

        private void AnswerBox_TextChanged(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void AnswerText_Click(object sender, EventArgs e)
        {

        }

        private void PortText_Click(object sender, EventArgs e)
        {

        }

        private void NameText_Click(object sender, EventArgs e)
        {

        }
    }
}
