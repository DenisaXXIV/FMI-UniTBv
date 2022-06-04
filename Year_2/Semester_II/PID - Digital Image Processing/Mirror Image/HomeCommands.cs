namespace ImageProcessingFramework.ViewModel
{
    class HomeCommands : INotifyPropertyChanged
    {
        public ImageSource InitialImage { get; set; }

        public ImageSource ProcessedImage { get; set; }

        private ICommand m_mirrorImage;

        public void MirrorImage(object parameter)
        {
            if (GrayInitialImage != null)
            {
                GrayProcessedImage = Tools.Mirror(GrayInitialImage);
                ProcessedImage = ImageConverter.Convert(GrayProcessedImage);
                OnPropertyChanged("ProcessedImage");
            }
            else if (ColorInitialImage != null)
            {
                ColorProcessedImage = Tools.Mirror(ColorInitialImage);
                ProcessedImage = ImageConverter.Convert(ColorProcessedImage);
                OnPropertyChanged("ProcessedImage");
            }
            else
                MessageBox.Show("Please add an image!");
        }

        public ICommand Mirror
        {
            get
            {
                if (m_mirrorImage == null)
                {
                    m_mirrorImage = new RelayCommand(MirrorImage);
                }
                return m_mirrorImage;
            }
        }
    }
}