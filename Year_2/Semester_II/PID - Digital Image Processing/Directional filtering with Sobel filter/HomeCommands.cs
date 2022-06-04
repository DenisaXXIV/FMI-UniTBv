namespace ImageProcessingFramework.ViewModel
{
    class HomeCommands : INotifyPropertyChanged
    {
        public ImageSource InitialImage { get; set; }

        public ImageSource ProcessedImage { get; set; }

        private ICommand m_Sobel;

        public void SobelFilter(object parameter)
        {
            var dialogBox = new DialogBox();
            var prop = new List<string>();
            prop.Add("Threshold");
            dialogBox.CreateDialogBox(prop);
            if (dialogBox.ShowDialog() == true)
            { }
            var response = dialogBox.GetResponseTexts();

            if (GrayInitialImage != null)
            {
                GrayProcessedImage = Tools.Sobel(GrayInitialImage, response[0]);
                ProcessedImage = ImageConverter.Convert(GrayProcessedImage);
                OnPropertyChanged("ProcessedImage");
            }
            else if (ColorInitialImage != null)
            {
                ColorInitialImage = Tools.Sobel(ColorInitialImage, response[0]);
                ProcessedImage = ImageConverter.Convert(ColorInitialImage);
                OnPropertyChanged("ProcessedImage");
            }
            else
                MessageBox.Show("Please add an image!");
        }

        public ICommand Sobel
        {
            get
            {
                if (m_Sobel == null)
                {
                    m_Sobel = new RelayCommand(SobelFilter);
                }

                return m_Sobel;
            }
        }

        public event PropertyChangedEventHandler PropertyChanged;

        private void OnPropertyChanged(string propertyName)
        {
            if (PropertyChanged != null)
            {
                PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
            }
        }
    }
}