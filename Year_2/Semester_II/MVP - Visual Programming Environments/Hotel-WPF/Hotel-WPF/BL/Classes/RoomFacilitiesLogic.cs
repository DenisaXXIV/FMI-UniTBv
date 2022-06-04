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
    internal class RoomFacilitiesLogic : IEntityLogic<RoomFacilitiesDTO>
    {
        private readonly IHotelRepository<RoomFacilities> _repository;
        private readonly IMapper _mapper;

        public RoomFacilitiesLogic(IHotelRepository<RoomFacilities> repository, IMapper mapper)
        {
            _repository = repository;
            _mapper = mapper;
        }

        public async Task Add(RoomFacilitiesDTO entityDTO)
        {
            if (entityDTO == null)
            {
                throw new ArgumentNullException(nameof(entityDTO));
            }
            try
            {
                var entity = _mapper.Map<RoomFacilities>(entityDTO);
                await _repository.Add(entity);
            }
            catch (DbUpdateException)
            {
                throw;
            }
        }

        public async Task<List<RoomFacilitiesDTO>> GetAll()
        {
            var results = _mapper.Map<List<RoomFacilitiesDTO>>(await _repository.GetAll());
            return results;
        }


        public async Task Remove(RoomFacilitiesDTO entityDTO)
        {
            if (entityDTO == null)
            {
                throw new ArgumentNullException(nameof(entityDTO));
            }
            try
            {
                await _repository.Delete(entityDTO.IdRoomFacilities);
            }
            catch (DbUpdateException)
            {
                throw;
            }
        }



        public async Task Update(RoomFacilitiesDTO entityDTO)
        {
            if (entityDTO == null)
            {
                throw new ArgumentNullException(nameof(entityDTO));
            }
            try
            {
                var entity = _mapper.Map<RoomFacilities>(entityDTO);
                await _repository.Update(entity);
            }
            catch (DbUpdateException)
            {
                throw;
            }
        }

        Task<RoomFacilitiesDTO> IEntityLogic<RoomFacilitiesDTO>.GetByName(string name)
        {
            throw new NotImplementedException();
        }
    }
}
