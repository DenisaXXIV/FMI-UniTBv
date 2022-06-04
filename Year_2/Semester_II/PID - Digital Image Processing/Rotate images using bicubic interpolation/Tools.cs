namespace ImageProcessingAlgorithms.Tools
{
    public class Tools
    {
        public static Image<Bgr, byte> CurrentGraphImage;

        public static Image<Gray, byte> Rotatie(Image<Gray, byte> inputImage, double response)
        {
            double radiani = response * (Math.PI / 180);

            Image<Gray, byte> newImage = new Image<Gray, byte>(inputImage.Size);

            for (int y = 1; y < newImage.Height - 2; y++)
            {
                for (int x = 1; x < newImage.Width - 2; x++)
                {
                    double xc = (x - newImage.Width / 2) * Math.Cos(radiani) + (y - newImage.Height / 2) * Math.Sin(radiani)
                        + newImage.Height / 2;
                    double yc = -(x - newImage.Width / 2) * Math.Sin(radiani) + (y - newImage.Height / 2) * Math.Cos(radiani)
                        + newImage.Width / 2;

                    double tx = xc - Math.Floor(xc);
                    double ty = yc - Math.Floor(yc);

                    int x0 = (int)xc;
                    int y0 = (int)yc;
                    List<double> listOfB = new List<double>();
                    if (x0 >= 1 && y0 >= 1 && x0 <= inputImage.Width - 3 && y0 <= inputImage.Height - 3)
                    {
                        for (int i = (int)yc - 1; i <= (int)yc + 2; i++)
                        {

                            listOfB.Add(BGetter(tx, inputImage.Data[i, (int)Math.Floor(xc) - 1, 0], inputImage.Data[i, (int)Math.Floor(xc), 0], inputImage.Data[i, (int)Math.Floor(xc) + 1, 0], inputImage.Data[i, (int)Math.Floor(xc) + 2, 0]));
                        }


                        int temp = (int)BGetter(ty, listOfB[0], listOfB[1], listOfB[2], listOfB[3]);

                        if (temp < 0)
                        {
                            temp = 0;
                        }
                        else if (temp > 255)
                        {
                            temp = 255;
                        }

                        newImage.Data[y, x, 0] = (byte)temp;
                    }
                    else
                    {
                        newImage.Data[y, x, 0] = (byte)0;
                    }
                }

            }

            return newImage;
        }

        public static Image<Bgr, byte> Rotatie(Image<Bgr, byte> inputImage, double response)
        {
            double radiani = response * (Math.PI / 180);

            Image<Bgr, byte> newImage = new Image<Bgr, byte>(inputImage.Size);

            for (int y = 1; y < newImage.Height - 2; y++)
            {
                for (int x = 1; x < newImage.Width - 2; x++)
                {
                    double xc = (x - newImage.Width / 2) * Math.Cos(radiani) + (y - newImage.Height / 2) * Math.Sin(radiani)
                        + newImage.Width / 2;
                    double yc = -(x - newImage.Width / 2) * Math.Sin(radiani) + (y - newImage.Height / 2) * Math.Cos(radiani)
                        + newImage.Height / 2;

                    double tx = xc - Math.Floor(xc);
                    double ty = yc - Math.Floor(yc);

                    int x0 = (int)xc;
                    int y0 = (int)yc;
                    List<double> listOfB0 = new List<double>();
                    List<double> listOfB1 = new List<double>();
                    List<double> listOfB2 = new List<double>();
                    if (x0 >= 1 && y0 >= 1 && x0 <= inputImage.Width - 3 && y0 <= inputImage.Height - 3)
                    {
                        for (int i = (int)yc - 1; i <= (int)yc + 2; i++)
                        {

                            listOfB0.Add(BGetter(tx, inputImage.Data[i, (int)Math.Floor(xc) - 1, 0], inputImage.Data[i, (int)Math.Floor(xc), 0], inputImage.Data[i, (int)Math.Floor(xc) + 1, 0], inputImage.Data[i, (int)Math.Floor(xc) + 2, 0]));
                            listOfB1.Add(BGetter(tx, inputImage.Data[i, (int)Math.Floor(xc) - 1, 1], inputImage.Data[i, (int)Math.Floor(xc), 1], inputImage.Data[i, (int)Math.Floor(xc) + 1, 1], inputImage.Data[i, (int)Math.Floor(xc) + 2, 1]));
                            listOfB2.Add(BGetter(tx, inputImage.Data[i, (int)Math.Floor(xc) - 1, 2], inputImage.Data[i, (int)Math.Floor(xc), 2], inputImage.Data[i, (int)Math.Floor(xc) + 1, 2], inputImage.Data[i, (int)Math.Floor(xc) + 2, 2]));
                        }


                        int temp = (int)BGetter(ty, listOfB0[0], listOfB0[1], listOfB0[2], listOfB0[3]);

                        if (temp < 0)
                        {
                            temp = 0;
                        }
                        else if (temp > 255)
                        {
                            temp = 255;
                        }

                        newImage.Data[y, x, 0] = (byte)temp;

                        temp = (int)BGetter(ty, listOfB1[0], listOfB1[1], listOfB1[2], listOfB1[3]);

                        if (temp < 0)
                        {
                            temp = 0;
                        }
                        else if (temp > 255)
                        {
                            temp = 255;
                        }

                        newImage.Data[y, x, 1] = (byte)temp;

                        temp = (int)BGetter(ty, listOfB2[0], listOfB2[1], listOfB2[2], listOfB2[3]);

                        if (temp < 0)
                        {
                            temp = 0;
                        }
                        else if (temp > 255)
                        {
                            temp = 255;
                        }

                        newImage.Data[y, x, 2] = (byte)temp;
                    }
                    else
                    {
                        newImage.Data[y, x, 0] = (byte)0;
                        newImage.Data[y, x, 1] = (byte)0;
                        newImage.Data[y, x, 2] = (byte)0;
                    }
                }

            }

            return newImage;
        }     
    }
}