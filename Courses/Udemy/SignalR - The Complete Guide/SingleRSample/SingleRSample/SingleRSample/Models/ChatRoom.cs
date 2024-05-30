using System.ComponentModel.DataAnnotations;

namespace SingleRSample.Models
{
    public class ChatRoom
    {
        public int Id { get; set; }

        [Required]
        public string Name { get; set; }
    }
}
