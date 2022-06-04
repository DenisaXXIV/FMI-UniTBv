namespace ImageProcessingFramework.ViewModel
{
    class HomeCommands : INotifyPropertyChanged
    {
        public ImageSource InitialImage { get; set; }

        public ImageSource ProcessedImage { get; set; }

        private ICommand m_binarize;

        public void Binarized(object parameter)
        {
            var dialogBox = new DialogBox();
            var prop = new List<string>();
            prop.Add("threshold");
            dialogBox.CreateDialogBox(prop);
            var response = dialogBox.GetResponseTexts();
            if (GrayInitialImage != null)
            {
                GrayProcessedImage = Tools.Binarize(GrayInitialImage, response[0]);
                ProcessedImage = ImageConverter.Convert(GrayProcessedImage);
                OnPropertyChanged("ProcessedImage");
            }
            else if (ColorInitialImage != null)
            {
                ColorProcessedImage = Tools.Binarize(ColorInitialImage, response[0]);
                ProcessedImage = ImageConverter.Convert(ColorProcessedImage);
                OnPropertyChanged("ProcessedImage");
            }
            else
                MessageBox.Show("Please add an image!");
        }

        public ICommand Binarize
        {
            get
            {
                if (m_binarize == null)
                {
                    m_binarize = new RelayCommand(Binarized);
                }
                return m_binarize;
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