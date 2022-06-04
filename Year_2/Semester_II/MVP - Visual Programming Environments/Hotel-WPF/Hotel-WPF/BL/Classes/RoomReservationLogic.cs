using AutoMapper;
using Hotel_WPF.BL.Interfaces;
using Hotel_WPF.DAL.Entities;
using Hotel_WPF.DAL.Interfaces;
using Hotel_WPF.TL.DTO;
using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hotel_WPF.BL.Classes
{
    internal class RoomReservationLogic : IEntityLogic<RoomReservationDTO>
    {
        private readonly IHotelRepository<RoomReservation> _repository;
        private readonly IMapper _mapper;

        public RoomReservationLogic(IHotelRepository<RoomReservation> repository, IMapper mapper)
        {
            _repository = repository;
            _mapper = mapper;
        }

        public async Task Add(RoomReservationDTO entityDTO)
        {
            if (entityDTO == null)
            {
                throw new ArgumentNullException(nameof(entityDTO));
            }
            try
            {
                var entity = _mapper.Map<RoomReservation>(entityDTO);
                await _repository.Add(entity);
            }
            catch (DbUpdateException)
            {
                throw;
            }
        }

        public async Task<List<RoomReservationDTO>> GetAll()
        {
            var results = _mapper.Map<List<RoomReservationDTO>>(await _repository.GetAll());
            return results;
        }


        public async Task Remove(RoomReservationDTO entityDTO)
        {
            if (entityDTO == null)
            {
                throw new ArgumentNullException(nameof(entityDTO));
            }
            try
            {
                await _repository.Delete(entityDTO.IdRoomReservation);
            }
            catch (DbUpdateException)
            {
                throw;
            }
        }



        public async Task Update(RoomReservationDTO entityDTO)
        {
            if (entityDTO == null)
            {
                throw new ArgumentNullException(nameof(entityDTO));
            }
            try
            {
                var entity = _mapper.Map<RoomReservation>(entityDTO);
                await _repository.Update(entity);
            }
            catch (DbUpdateException)
            {
                throw;
            }
        }

        Task<RoomReservationDTO> IEntityLogic<RoomReservationDTO>.GetByName(string name)
        {
            throw new NotImplementedException();
        }
    }
}
