namespace ImageProcessingAlgorithms.Tools
{
    public class Tools
    {
        public static Image<Bgr, byte> CurrentGraphImage;

        public static Image<Gray, byte> Mirror(Image<Gray, byte> inputImage)
        {
            var results = new Image<Gray, byte>(inputImage.Size);

            results = inputImage.Flip(FlipType.Horizontal);

            return results;
        }

        public static Image<Bgr, byte> Mirror(Image<Bgr, byte> inputImage)
        {
            var results = new Image<Bgr, byte>(inputImage.Size);

            results = inputImage.Flip(FlipType.Horizontal);

            return results;
        }
    }
}