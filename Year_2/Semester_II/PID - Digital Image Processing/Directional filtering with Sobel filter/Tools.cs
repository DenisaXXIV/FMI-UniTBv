namespace ImageProcessingAlgorithms.Tools
{
    public class Tools
    {
        public static Image<Bgr, byte> CurrentGraphImage;

        public static Image<Gray, byte> Sobel(Image<Gray, byte> inputImage, double response)
        {
            var results = new Image<Gray, byte>(inputImage.Size);
            float Sx, Sy;

            //List<List<float>> sx = new List<List<float>>();
            //List<float> list1 = new List<float>() { -1f, 0f, 1f };
            //List<float> list2 = new List<float>() { -2f, 0f, 2f };
            //List<float> list3 = new List<float>() { -1f, 0f, 1f };
            //sx.Add(list1);
            //sx.Add(list2);
            //sx.Add(list3);

            //List<List<float>> sy = new List<List<float>>();
            //List<float> list4 = new List<float>() { -1f, -2f, -1f };
            //List<float> list5 = new List<float>() { 0f, 0f, 0f };
            //List<float> list6 = new List<float>() { 1f, 2f, 1f };
            //sy.Add(list4);
            //sy.Add(list5);
            //sy.Add(list6);

            for (int y = 0; y < inputImage.Height; y++)
            {
                for (int x = 0; x < inputImage.Width; x++)
                {
                    if (x == 0 && y == 0)
                    {
                        Sx = inputImage.Data[1, 1, 0] + (inputImage.Data[1, 0, 0] * 2);
                        Sy = (inputImage.Data[0, 1, 0] * 2) + (inputImage.Data[1, 1, 0] * 1);
                    }
                    else
                    {
                        if (x == 0 && y == inputImage.Height - 1)
                        {
                            Sx = (inputImage.Data[inputImage.Height - 2, 0, 0] * (-2)) + (inputImage.Data[inputImage.Height - 2, 1, 0] * (-1));
                            Sy = inputImage.Data[inputImage.Height - 2, 1, 0] + (inputImage.Data[inputImage.Height - 1, 1, 0] * 2);
                        }
                        else
                        {
                            if (x == inputImage.Width - 1 && y == 0)
                            {
                                Sx = (inputImage.Data[1, inputImage.Width - 2, 0] * 1) + (inputImage.Data[1, inputImage.Width - 1, 0] * 2);
                                Sy = (inputImage.Data[0, inputImage.Width - 2, 0] * (-2)) + (inputImage.Data[1, inputImage.Width - 2, 0] * (-1));
                            }
                            else
                            {
                                if (x == inputImage.Width - 1 && y == inputImage.Height - 1)
                                {
                                    Sx = (inputImage.Data[inputImage.Height - 2, inputImage.Width - 2, 0] * (-1)) + (inputImage.Data[inputImage.Height - 2, inputImage.Width - 1, 0] * (-2));
                                    Sy = (inputImage.Data[inputImage.Height - 2, inputImage.Width - 2, 0] * (-1)) + (inputImage.Data[inputImage.Height - 1, inputImage.Width - 2, 0] * (-2));
                                }
                                else
                                {
                                    if ((y != 0 || y != inputImage.Height - 1) && x == 0)
                                    {
                                        Sx = (inputImage.Data[y - 1, x, 0] * (-2)) + (inputImage.Data[y - 1, x + 1, 0] * (-1)) +
                                            (inputImage.Data[y + 1, x, 0] * 2) + (inputImage.Data[y + 1, x + 1, 0] * 1);
                                        Sy = (inputImage.Data[y - 1, x + 1, 0] * 1) + (inputImage.Data[y, x + 1, 0] * 2) +
                                            (inputImage.Data[y + 1, x + 1, 0] * 1);
                                    }
                                    else
                                    {
                                        if ((x != 0 || x != inputImage.Width - 1) && y == 0)
                                        {
                                            Sx = (inputImage.Data[y + 1, x - 1, 0] * 1) + (inputImage.Data[y + 1, x, 0] * 2) +
                                                (inputImage.Data[y + 1, x + 1, 0] * 1);
                                            Sy = (inputImage.Data[y, x - 1, 0] * (-2)) + (inputImage.Data[y + 1, x - 1, 0] * (-1)) +
                                                (inputImage.Data[y, x + 1, 0] * 2) + (inputImage.Data[y + 1, x + 1, 0] * 1);
                                        }
                                        else
                                        {
                                            if ((y != 0 || y != inputImage.Height - 1) && x == inputImage.Width - 1)
                                            {
                                                Sx = (inputImage.Data[y - 1, x - 1, 0] * (-1)) + (inputImage.Data[y - 1, x, 0] * (-2)) +
                                                (inputImage.Data[y + 1, x - 1, 0] * 1) + (inputImage.Data[y + 1, x, 0] * 2);
                                                Sy = (inputImage.Data[y - 1, x - 1, 0] * (-1)) + (inputImage.Data[y, x - 1, 0] * (-2)) +
                                                    (inputImage.Data[y + 1, x - 1, 0] * (-1));
                                            }
                                            else
                                            {
                                                if ((x != 0 || x != inputImage.Width - 1) && y == inputImage.Height - 1)
                                                {
                                                    Sx = (inputImage.Data[y - 1, x - 1, 0] * (-1)) + (inputImage.Data[y - 1, x, 0] * (-2)) +
                                                (inputImage.Data[y - 1, x + 1, 0] * (-1));
                                                    Sy = (inputImage.Data[y - 1, x - 1, 0] * (-1)) + (inputImage.Data[y, x - 1, 0] * (-2)) +
                                                        (inputImage.Data[y - 1, x + 1, 0] * 1) + (inputImage.Data[y, x + 1, 0] * 2);
                                                }
                                                else
                                                {
                                                    Sx = (inputImage.Data[y - 1, x - 1, 0] * (-1)) + (inputImage.Data[y - 1, x, 0] * (-2)) +
                                                        (inputImage.Data[y - 1, x + 1, 0] * (-1)) + (inputImage.Data[y + 1, x - 1, 0] * 1) +
                                                        (inputImage.Data[y + 1, x, 0] * 2) + (inputImage.Data[y + 1, x + 1, 0] * 1);
                                                    Sy = (inputImage.Data[y - 1, x - 1, 0] * (-1)) + (inputImage.Data[y, x - 1, 0] * (-2)) +
                                                        (inputImage.Data[y + 1, x - 1, 0] * (-1)) + (inputImage.Data[y - 1, x + 1, 0] * 1) +
                                                        (inputImage.Data[y, x + 1, 0] * 2) + (inputImage.Data[y + 1, x + 1, 0] * 1);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }

                    double angle = Math.Atan2(Sy, Sx) * (180 / Math.PI);
                    var G = Math.Sqrt(Math.Pow(Sx, 2) + Math.Pow(Sy, 2));
                    double yColor = ((angle + 180) * 128 / 360) + 127;

                    if (G >= response)
                    {
                        results.Data[y, x, 0] = (byte)yColor;
                    }
                    else
                    {
                        results.Data[y, x, 0] = (byte)0;
                    }
                }
            }

            return results;

        }
            
        public static Image<Bgr, byte> Sobel(Image<Bgr, byte> inputImage, double response)
        {
            var results = new Image<Bgr, byte>(inputImage.Size);
            float Sx1, Sx2, Sx3, Sy1, Sy2, Sy3;

            //List<List<float>> sx = new List<List<float>>();
            //List<float> list1 = new List<float>() { -1f, 0f, 1f };
            //List<float> list2 = new List<float>() { -2f, 0f, 2f };
            //List<float> list3 = new List<float>() { -1f, 0f, 1f };
            //sx.Add(list1);
            //sx.Add(list2);
            //sx.Add(list3);

            //List<List<float>> sy = new List<List<float>>();
            //List<float> list4 = new List<float>() { -1f, -2f, -1f };
            //List<float> list5 = new List<float>() { 0f, 0f, 0f };
            //List<float> list6 = new List<float>() { 1f, 2f, 1f };
            //sy.Add(list4);
            //sy.Add(list5);
            //sy.Add(list6);

            for (int y = 0; y < inputImage.Height; y++)
            {
                for (int x = 0; x < inputImage.Width; x++)
                {
                    if (x == 0 && y == 0)
                    {
                        Sx1 = inputImage.Data[1, 1, 0] + (inputImage.Data[1, 0, 0] * 2);
                        Sy1 = (inputImage.Data[0, 1, 0] * 2) + (inputImage.Data[1, 1, 0] * 1);

                        Sx2 = inputImage.Data[1, 1, 1] + (inputImage.Data[1, 0, 1] * 2);
                        Sy2 = (inputImage.Data[0, 1, 1] * 2) + (inputImage.Data[1, 1, 1] * 1);

                        Sx3 = inputImage.Data[1, 1, 2] + (inputImage.Data[1, 0, 2] * 2);
                        Sy3 = (inputImage.Data[0, 1, 2] * 2) + (inputImage.Data[1, 1, 2] * 1);
                    }
                    else
                    {
                        if (x == 0 && y == inputImage.Height - 1)
                        {
                            Sx1 = (inputImage.Data[inputImage.Height - 2, 0, 0] * (-2)) + (inputImage.Data[inputImage.Height - 2, 1, 0] * (-1));
                            Sy1 = inputImage.Data[inputImage.Height - 2, 1, 0] + (inputImage.Data[inputImage.Height - 1, 1, 0] * 2);

                            Sx2 = (inputImage.Data[inputImage.Height - 2, 0, 1] * (-2)) + (inputImage.Data[inputImage.Height - 2, 1, 1] * (-1));
                            Sy2 = inputImage.Data[inputImage.Height - 2, 1, 1] + (inputImage.Data[inputImage.Height - 1, 1, 1] * 2);

                            Sx3 = (inputImage.Data[inputImage.Height - 2, 0, 2] * (-2)) + (inputImage.Data[inputImage.Height - 2, 1, 2] * (-1));
                            Sy3 = inputImage.Data[inputImage.Height - 2, 1, 2] + (inputImage.Data[inputImage.Height - 1, 1, 2] * 2);
                        }
                        else
                        {
                            if (x == inputImage.Width - 1 && y == 0)
                            {
                                Sx1 = (inputImage.Data[1, inputImage.Width - 2, 0] * 1) + (inputImage.Data[1, inputImage.Width - 1, 0] * 2);
                                Sy1 = (inputImage.Data[0, inputImage.Width - 2, 0] * (-2)) + (inputImage.Data[1, inputImage.Width - 2, 0] * (-1));

                                Sx2 = (inputImage.Data[1, inputImage.Width - 2, 1] * 1) + (inputImage.Data[1, inputImage.Width - 1, 1] * 2);
                                Sy2 = (inputImage.Data[0, inputImage.Width - 2, 1] * (-2)) + (inputImage.Data[1, inputImage.Width - 2, 1] * (-1));

                                Sx3 = (inputImage.Data[1, inputImage.Width - 2, 2] * 1) + (inputImage.Data[1, inputImage.Width - 1, 2] * 2);
                                Sy3 = (inputImage.Data[0, inputImage.Width - 2, 2] * (-2)) + (inputImage.Data[1, inputImage.Width - 2, 2] * (-1));
                            }
                            else
                            {
                                if (x == inputImage.Width - 1 && y == inputImage.Height - 1)
                                {
                                    Sx1 = (inputImage.Data[inputImage.Height - 2, inputImage.Width - 2, 0] * (-1)) + (inputImage.Data[inputImage.Height - 2, inputImage.Width - 1, 0] * (-2));
                                    Sy1 = (inputImage.Data[inputImage.Height - 2, inputImage.Width - 2, 0] * (-1)) + (inputImage.Data[inputImage.Height - 1, inputImage.Width - 2, 0] * (-2));

                                    Sx2 = (inputImage.Data[inputImage.Height - 2, inputImage.Width - 2, 1] * (-1)) + (inputImage.Data[inputImage.Height - 2, inputImage.Width - 1, 1] * (-2));
                                    Sy2 = (inputImage.Data[inputImage.Height - 2, inputImage.Width - 2, 1] * (-1)) + (inputImage.Data[inputImage.Height - 1, inputImage.Width - 2, 1] * (-2));

                                    Sx3 = (inputImage.Data[inputImage.Height - 2, inputImage.Width - 2, 2] * (-1)) + (inputImage.Data[inputImage.Height - 2, inputImage.Width - 1, 2] * (-2));
                                    Sy3 = (inputImage.Data[inputImage.Height - 2, inputImage.Width - 2, 2] * (-1)) + (inputImage.Data[inputImage.Height - 1, inputImage.Width - 2, 2] * (-2));
                                }
                                else
                                {
                                    if ((y != 0 || y != inputImage.Height - 1) && x == 0)
                                    {
                                        Sx1 = (inputImage.Data[y - 1, x, 0] * (-2)) + (inputImage.Data[y - 1, x + 1, 0] * (-1)) +
                                            (inputImage.Data[y + 1, x, 0] * 2) + (inputImage.Data[y + 1, x + 1, 0] * 1);
                                        Sy1 = (inputImage.Data[y - 1, x + 1, 0] * 1) + (inputImage.Data[y, x + 1, 0] * 2) +
                                            (inputImage.Data[y + 1, x + 1, 0] * 1);

                                        Sx2 = (inputImage.Data[y - 1, x, 1] * (-2)) + (inputImage.Data[y - 1, x + 1, 1] * (-1)) +
                                            (inputImage.Data[y + 1, x, 1] * 2) + (inputImage.Data[y + 1, x + 1, 1] * 1);
                                        Sy2 = (inputImage.Data[y - 1, x + 1, 1] * 1) + (inputImage.Data[y, x + 1, 1] * 2) +
                                            (inputImage.Data[y + 1, x + 1, 1] * 1);

                                        Sx3 = (inputImage.Data[y - 1, x, 2] * (-2)) + (inputImage.Data[y - 1, x + 1, 2] * (-1)) +
                                            (inputImage.Data[y + 1, x, 2] * 2) + (inputImage.Data[y + 1, x + 1, 2] * 1);
                                        Sy3 = (inputImage.Data[y - 1, x + 1, 2] * 1) + (inputImage.Data[y, x + 1, 2] * 2) +
                                            (inputImage.Data[y + 1, x + 1, 2] * 1);
                                    }
                                    else
                                    {
                                        if ((x != 0 || x != inputImage.Width - 1) && y == 0)
                                        {
                                            Sx1 = (inputImage.Data[y + 1, x - 1, 0] * 1) + (inputImage.Data[y + 1, x, 0] * 2) +
                                                (inputImage.Data[y + 1, x + 1, 0] * 1);
                                            Sy1 = (inputImage.Data[y, x - 1, 0] * (-2)) + (inputImage.Data[y + 1, x - 1, 0] * (-1)) +
                                                (inputImage.Data[y, x + 1, 0] * 2) + (inputImage.Data[y + 1, x + 1, 0] * 1);

                                            Sx2 = (inputImage.Data[y + 1, x - 1, 1] * 1) + (inputImage.Data[y + 1, x, 1] * 2) +
                                                (inputImage.Data[y + 1, x + 1, 1] * 1);
                                            Sy2 = (inputImage.Data[y, x - 1, 1] * (-2)) + (inputImage.Data[y + 1, x - 1, 1] * (-1)) +
                                                (inputImage.Data[y, x + 1, 1] * 2) + (inputImage.Data[y + 1, x + 1, 1] * 1);

                                            Sx3 = (inputImage.Data[y + 1, x - 1, 2] * 1) + (inputImage.Data[y + 1, x, 2] * 2) +
                                                (inputImage.Data[y + 1, x + 1, 2] * 1);
                                            Sy3 = (inputImage.Data[y, x - 1, 2] * (-2)) + (inputImage.Data[y + 1, x - 1, 2] * (-1)) +
                                                (inputImage.Data[y, x + 1, 2] * 2) + (inputImage.Data[y + 1, x + 1, 2] * 1);
                                        }
                                        else
                                        {
                                            if ((y != 0 || y != inputImage.Height - 1) && x == inputImage.Width - 1)
                                            {
                                                Sx1 = (inputImage.Data[y - 1, x - 1, 0] * (-1)) + (inputImage.Data[y - 1, x, 0] * (-2)) +
                                                (inputImage.Data[y + 1, x - 1, 0] * 1) + (inputImage.Data[y + 1, x, 0] * 2);
                                                Sy1 = (inputImage.Data[y - 1, x - 1, 0] * (-1)) + (inputImage.Data[y, x - 1, 0] * (-2)) +
                                                    (inputImage.Data[y + 1, x - 1, 0] * (-1));

                                                Sx2 = (inputImage.Data[y - 1, x - 1, 1] * (-1)) + (inputImage.Data[y - 1, x, 1] * (-2)) +
                                                (inputImage.Data[y + 1, x - 1, 1] * 1) + (inputImage.Data[y + 1, x, 1] * 2);
                                                Sy2 = (inputImage.Data[y - 1, x - 1, 1] * (-1)) + (inputImage.Data[y, x - 1, 1] * (-2)) +
                                                    (inputImage.Data[y + 1, x - 1, 1] * (-1));

                                                Sx3 = (inputImage.Data[y - 1, x - 1, 2] * (-1)) + (inputImage.Data[y - 1, x, 2] * (-2)) +
                                                (inputImage.Data[y + 1, x - 1, 2] * 1) + (inputImage.Data[y + 1, x, 2] * 2);
                                                Sy3 = (inputImage.Data[y - 1, x - 1, 2] * (-1)) + (inputImage.Data[y, x - 1, 2] * (-2)) +
                                                    (inputImage.Data[y + 1, x - 1, 2] * (-1));
                                            }
                                            else
                                            {
                                                if ((x != 0 || x != inputImage.Width - 1) && y == inputImage.Height - 1)
                                                {
                                                    Sx1 = (inputImage.Data[y - 1, x - 1, 0] * (-1)) + (inputImage.Data[y - 1, x, 0] * (-2)) +
                                                (inputImage.Data[y - 1, x + 1, 0] * (-1));
                                                    Sy1 = (inputImage.Data[y - 1, x - 1, 0] * (-1)) + (inputImage.Data[y, x - 1, 0] * (-2)) +
                                                        (inputImage.Data[y - 1, x + 1, 0] * 1) + (inputImage.Data[y, x + 1, 0] * 2);

                                                    Sx2 = (inputImage.Data[y - 1, x - 1, 1] * (-1)) + (inputImage.Data[y - 1, x, 1] * (-2)) +
                                                (inputImage.Data[y - 1, x + 1, 1] * (-1));
                                                    Sy2 = (inputImage.Data[y - 1, x - 1, 1] * (-1)) + (inputImage.Data[y, x - 1, 1] * (-2)) +
                                                        (inputImage.Data[y - 1, x + 1, 1] * 1) + (inputImage.Data[y, x + 1, 1] * 2);

                                                    Sx3 = (inputImage.Data[y - 1, x - 1, 2] * (-1)) + (inputImage.Data[y - 1, x, 2] * (-2)) +
                                                (inputImage.Data[y - 1, x + 1, 2] * (-1));
                                                    Sy3 = (inputImage.Data[y - 1, x - 1, 2] * (-1)) + (inputImage.Data[y, x - 1, 2] * (-2)) +
                                                        (inputImage.Data[y - 1, x + 1, 2] * 1) + (inputImage.Data[y, x + 1, 2] * 2);
                                                }
                                                else
                                                {
                                                    Sx1 = (inputImage.Data[y - 1, x - 1, 0] * (-1)) + (inputImage.Data[y - 1, x, 0] * (-2)) +
                                                        (inputImage.Data[y - 1, x + 1, 0] * (-1)) + (inputImage.Data[y + 1, x - 1, 0] * 1) +
                                                        (inputImage.Data[y + 1, x, 0] * 2) + (inputImage.Data[y + 1, x + 1, 0] * 1);
                                                    Sy1 = (inputImage.Data[y - 1, x - 1, 0] * (-1)) + (inputImage.Data[y, x - 1, 0] * (-2)) +
                                                        (inputImage.Data[y + 1, x - 1, 0] * (-1)) + (inputImage.Data[y - 1, x + 1, 0] * 1) +
                                                        (inputImage.Data[y, x + 1, 0] * 2) + (inputImage.Data[y + 1, x + 1, 0] * 1);

                                                    Sx2 = (inputImage.Data[y - 1, x - 1, 1] * (-1)) + (inputImage.Data[y - 1, x, 1] * (-2)) +
                                                        (inputImage.Data[y - 1, x + 1, 1] * (-1)) + (inputImage.Data[y + 1, x - 1, 1] * 1) +
                                                        (inputImage.Data[y + 1, x, 1] * 2) + (inputImage.Data[y + 1, x + 1, 1] * 1);
                                                    Sy2 = (inputImage.Data[y - 1, x - 1, 1] * (-1)) + (inputImage.Data[y, x - 1, 1] * (-2)) +
                                                        (inputImage.Data[y + 1, x - 1, 1] * (-1)) + (inputImage.Data[y - 1, x + 1, 1] * 1) +
                                                        (inputImage.Data[y, x + 1, 1] * 2) + (inputImage.Data[y + 1, x + 1, 1] * 1);

                                                    Sx3 = (inputImage.Data[y - 1, x - 1, 2] * (-1)) + (inputImage.Data[y - 1, x, 2] * (-2)) +
                                                        (inputImage.Data[y - 1, x + 1, 2] * (-1)) + (inputImage.Data[y + 1, x - 1, 2] * 1) +
                                                        (inputImage.Data[y + 1, x, 2] * 2) + (inputImage.Data[y + 1, x + 1, 2] * 1);
                                                    Sy3 = (inputImage.Data[y - 1, x - 1, 2] * (-1)) + (inputImage.Data[y, x - 1, 2] * (-2)) +
                                                        (inputImage.Data[y + 1, x - 1, 2] * (-1)) + (inputImage.Data[y - 1, x + 1, 2] * 1) +
                                                        (inputImage.Data[y, x + 1, 2] * 2) + (inputImage.Data[y + 1, x + 1, 2] * 1);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }

                    double angle1 = Math.Atan2(Sy1, Sx1) * (180 / Math.PI);
                    var G1 = (byte)Math.Sqrt(Math.Pow(Sx1, 2) + Math.Pow(Sy1, 2));
                    double yColor1 = ((angle1 + 180) * 128 / 360) + 127;

                    if (G1 >= response)
                    {
                        results.Data[y, x, 0] = (byte)yColor1;
                    }
                    else
                    {
                        results.Data[y, x, 0] = (byte)0;
                    }

                    double angle2 = Math.Atan2(Sy2, Sx2) * (180 / Math.PI);
                    var G2 = (byte)Math.Sqrt(Math.Pow(Sx2, 2) + Math.Pow(Sy2, 2));
                    double yColor2 = ((angle2 + 180) * 128 / 360) + 127;

                    if (G2 >= response)
                    {
                        results.Data[y, x, 1] = (byte)yColor2;
                    }
                    else
                    {
                        results.Data[y, x, 1] = (byte)0;
                    }

                    double angle3 = Math.Atan2(Sy3, Sx3) * (180 / Math.PI);
                    var G3 = (byte)Math.Sqrt(Math.Pow(Sx3, 2) + Math.Pow(Sy3, 2));
                    double yColor3 = ((angle3 + 180) * 128 / 360) + 127;

                    if (G3 >= response)
                    {
                        results.Data[y, x, 2] = (byte)yColor3;
                    }
                    else
                    {
                        results.Data[y, x, 2] = (byte)0;
                    }
                }
            }

            return results;

        }
    }
}