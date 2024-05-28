using Microsoft.AspNetCore.SignalR;

namespace SingleRSample.Hubs
{
    public class DeathlyHallowsHub : Hub
    {
        public Dictionary<string,int> GetRaceStatus()
        {
            return SD.DealthyHallowRace;
        }
    }
}
