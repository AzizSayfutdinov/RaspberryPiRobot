using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;
using System.Threading;

using CroUI.Robot;

namespace CroUI
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    /// 

    public partial class MainWindow : Window
    {

        private RaspPiRobot robot;
        private bool isLooping = false;

        public MainWindow()
        {
            InitializeComponent();
            robot = new RaspPiRobot();
            robot.sendStatusMessage('x');
          
        }

        // *** Connect Button
        private void buttonConnect_Click(object sender, RoutedEventArgs e)
        {
            // ToDo
            // Start Client Object here and try connect to server (Raspi)
            buttonConnect.Content = "Connecting...";
            //buttonConnect.Foreground = new SolidColorBrush(Colors.Gold);
            try
            {
                // tcpClient.Connect(IPAddress.Parse(textBoxIP.Text), 9999);
                buttonConnect.Content = "Connected";
                buttonConnect.Foreground = new SolidColorBrush(Colors.ForestGreen);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
                buttonConnect.Content = "Error";
                buttonConnect.Foreground = new SolidColorBrush(Colors.DarkRed);
            }

        }

        // *** Shape Buttons

        private void buttonRectangle_Click(object sender, RoutedEventArgs e)
        {
            // ToDo
            // Robot.moveRectangle();
        }

        private void buttonCircle_Click(object sender, RoutedEventArgs e)
        {
            // ToDo
            // Robot.moveCircle();
        }

        private void buttonTriangle_Click(object sender, RoutedEventArgs e)
        {
            // ToDo
            // Robot.moveTriangle();
        }

        private void buttonStar_Click(object sender, RoutedEventArgs e)
        {
            // ToDo
            // Robot.moveStar();
        }

        // Effect Buttons

        private void buttonLed_Click(object sender, RoutedEventArgs e)
        {
            // ToDo
            // Robot.ledEffect();
        }

        private void buttonMusic_Click(object sender, RoutedEventArgs e)
        {
            // ToDo
            // Robot.playMusic();
        }

        private void buttonAlign_Click(object sender, RoutedEventArgs e)
        {
            robot.alignNorth();
        }

        // Arrow Buttons

        private void Window_PreviewKeyDown(object sender, KeyEventArgs e)
        {
            if (e.Key == Key.Up)
            {
                textBoxStatus.Text = "Driving forward...";
                // setBtnPressedDesign(rButtonArrowUp);
                // ToDo
                // Robot.moveForward(sliderSpeed.value);
            }
            if (e.Key == Key.Left)
            {
                textBoxStatus.Text = "Driving to the left...";
                // setBtnPressedDesign(buttonArrowLeft);
                // ToDo
                // Robot.moveLeft(sliderSpeed.value);
            }
            if (e.Key == Key.Right)
            {
                textBoxStatus.Text = "Driving to the right...";
                // setBtnPressedDesign(buttonArrowRight);
                // ToDo
                // Robot.moveright(sliderSpeed.value);
            }
            if (e.Key == Key.Down)
            {
                textBoxStatus.Text = "Driving backwards...";
                // setBtnPressedDesign(buttonArrowDown);
                // ToDo
                // Robot.moveBackwards(sliderSpeed.value);
            }
        }

        private void Window_PreviewKeyUp(object sender, KeyEventArgs e)
        {
            clearTextBoxStatus();

            if (e.Key == Key.Up)
            {
                // resetBtnDesign(buttonArrowUp);
            }
            if (e.Key == Key.Left)
            {
                // resetBtnDesign(buttonArrowLeft);
            }
            if (e.Key == Key.Right)
            {
                // resetBtnDesign(buttonArrowRight);
            }
            if (e.Key == Key.Down)
            {
                // resetBtnDesign(buttonArrowDown);
            }
        }

        private void runLoop()
        {
            while (isLooping)
            {
                textBoxStatus.Text = "Driving forward...";
                // setBtnPressedDesign(buttonArrowUp);
                // ToDo
                robot.move((int)sliderSpeed.Value);
            }

        }

        private void buttonArrowUp_PreviewMouseDown(object sender, MouseButtonEventArgs e)      // Click event method
        {            
             textBoxStatus.Text = "Driving forward...";
             // setBtnPressedDesign(buttonArrowUp);
             // ToDo
             robot.move((int)sliderSpeed.Value);
        }


        private void buttonArrowLeft_PreviewMouseDown(object sender, MouseButtonEventArgs e)
        {
            textBoxStatus.Text = "Driving to the left...";
            // setBtnPressedDesign(buttonArrowLeft);
            // ToDo
            robot.turnLeft();
        }

        private void buttonArrowRight_PreviewMouseDown(object sender, MouseButtonEventArgs e)
        {
            textBoxStatus.Text = "Driving to the right...";
            // setBtnPressedDesign(buttonArrowRight);
            // ToDo
            robot.turnRight();
        }

        private void buttonArrowDown_PreviewMouseDown(object sender, MouseButtonEventArgs e)
        {
            textBoxStatus.Text = "Driving backwards...";
            // setBtnPressedDesign(buttonArrowDown);
            // ToDo
            robot.move(-(int)sliderSpeed.Value);
        }

        private void buttonArrow_PreviewMouseUp(object sender, MouseButtonEventArgs e)
        {
            clearTextBoxStatus();
            // resetBtnDesign((Button)sender);
            isLooping = false;
        }

        private void buttonArrow_MouseEnter(object sender, MouseEventArgs e)
        {
            // setBtnMouseoverDesign((Button)sender);
        }

        private void buttonArrow_MouseLeave(object sender, MouseEventArgs e)
        {
            // resetBtnDesign((Button)sender);
        }

        private void clearTextBoxStatus()
        {
            textBoxStatus.Text = "";
        }

        private void sliderSpeed_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            // Determine if a button is currently pressed - if yes which one?
            // Adjust the speed of the movement
            // arcSpeed.EndAngle = sliderSpeed.Value - 120;
            textSpeed.Text = ((int)sliderSpeed.Value).ToString();
        }

        private void rButtonArrowUp_Click(object sender, RoutedEventArgs e)
        {
            textBoxStatus.Text = "Driving forward...";
            // setBtnPressedDesign(buttonArrowUp);
            // ToDo
            robot.move((int)sliderSpeed.Value);
        }

        // private void setBtnPressedDesign(Button btn)
        // {
        //     var gradientStopCollection = new GradientStopCollection();
        //     gradientStopCollection.Add(new GradientStop(Colors.AliceBlue, 0.0));
        //     gradientStopCollection.Add(new GradientStop(Colors.CornflowerBlue, 0.5));
        //     gradientStopCollection.Add(new GradientStop(Colors.RoyalBlue, 1));
        //     btn.Background = new LinearGradientBrush(gradientStopCollection, new Point(0.5, 0), new Point(0.5, 1));
        // }
        // 
        // private void setBtnMouseoverDesign(Button btn)
        // {
        //     var gradientStopCollection = new GradientStopCollection();
        //     gradientStopCollection.Add(new GradientStop(Colors.WhiteSmoke, 0.0));
        //     gradientStopCollection.Add(new GradientStop(Colors.LightGray, 0.5));
        //     gradientStopCollection.Add(new GradientStop(Colors.Silver, 1));
        //     btn.Background = new LinearGradientBrush(gradientStopCollection, new Point(0.5, 0), new Point(0.5, 1));
        // }
        // 
        // private void resetBtnDesign(Button btn)
        // {
        //     var gradientStopCollection = new GradientStopCollection();
        //     gradientStopCollection.Add(new GradientStop(Colors.WhiteSmoke, 0.0));
        //     gradientStopCollection.Add(new GradientStop(Colors.LightGray, 0.25));
        //     gradientStopCollection.Add(new GradientStop(Colors.DimGray, 1));
        //     btn.Background = new LinearGradientBrush(gradientStopCollection, new Point(0.5, 0), new Point(0.5, 1));
        // }

    }
}
