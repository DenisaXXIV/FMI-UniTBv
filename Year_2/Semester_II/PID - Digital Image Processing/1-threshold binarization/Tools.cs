namespace ImageProcessingAlgorithms.Tools
{
    public class Tools
    {
        public static int threshold = 170;
        public static Image<Bgr, byte> CurrentGraphImage;

        public static Image<Gray, byte> Binarize(Image<Gray, byte> inputImage, double response)
        {
            var medium = GetMedium(inputImage);
            var result = new Image<Gray, byte>(inputImage.Size);
            for (int index1 = 0; index1 < inputImage.Height; index1++)
            {
                for (int index2 = 0; index2 < inputImage.Width; index2++)
                {
                    if (inputImage.Data[index1, index2, 0] <= response)
                    {
                        result.Data[index1, index2, 0] = 0;
                        continue;
                    }
                    else
                    {
                        result.Data[index1, index2, 0] = 255;
                    }
                }
            }
            return result;
        }

        public static Image<Bgr, byte> Binarize(Image<Bgr, byte> inputImage, double response)
        {
            var medium = GetMedium(inputImage);
            var result = new Image<Bgr, byte>(inputImage.Size);
            for (int index1 = 0; index1 < inputImage.Height; index1++)
            {
                for (int index2 = 0; index2 < inputImage.Width; index2++)
                {
                    if (inputImage.Data[index1, index2, 0] <= response)
                    {
                        result.Data[index1, index2, 0] = 0;
                        result.Data[index1, index2, 1] = 0;
                        result.Data[index1, index2, 2] = 0;
                        continue;
                    }
                    else
                    {
                        result.Data[index1, index2, 0] = 255;
                        result.Data[index1, index2, 1] = 255;
                        result.Data[index1, index2, 2] = 255;
                    }
                }
            }
            return result;
        }
    }
}