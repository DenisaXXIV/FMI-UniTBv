namespace ImageProcessingFramework.ViewModel
{
    class HomeCommands : INotifyPropertyChanged
    {
        public ImageSource InitialImage { get; set; }

        public ImageSource ProcessedImage { get; set; }

        private ICommand m_rotatie;

        public void RotatieInterpolare(object parameter)
        {
            var dialogBox = new DialogBox();
            var prop = new List<string>();
            prop.Add("Unghiul de rotatie (in grade)");
            dialogBox.CreateDialogBox(prop);
            if (dialogBox.ShowDialog() == true)
            { }
            var response = dialogBox.GetResponseTexts();

            if (GrayInitialImage != null)
            {
                GrayProcessedImage = Tools.Rotatie(GrayInitialImage, response[0]);
                ProcessedImage = ImageConverter.Convert(GrayProcessedImage);
                OnPropertyChanged("ProcessedImage");
            }
            else if (ColorInitialImage != null)
            {
                ColorInitialImage = Tools.Rotatie(ColorInitialImage, response[0]);
                ProcessedImage = ImageConverter.Convert(ColorInitialImage);
                OnPropertyChanged("ProcessedImage");
            }
            else
                MessageBox.Show("Please add an image!");
        }

        public ICommand Rotatie
        {
            get
            {
                if (m_rotatie == null)
                {
                    m_rotatie = new RelayCommand(RotatieInterpolare);
                }

                return m_rotatie;
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