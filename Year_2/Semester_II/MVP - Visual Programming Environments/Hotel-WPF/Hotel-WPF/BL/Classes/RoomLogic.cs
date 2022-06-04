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
    internal class RoomLogic : IEntityLogic<RoomDTO>
    {
        private readonly IHotelRepository<Room> _repository;
        private readonly IMapper _mapper;

        public RoomLogic(IHotelRepository<Room> repository, IMapper mapper)
        {
            _repository = repository;
            _mapper = mapper;
        }

        public async Task Add(RoomDTO entityDTO)
        {
            if (entityDTO == null)
            {
                throw new ArgumentNullException(nameof(entityDTO));
            }
            try
            {
                var entity = _mapper.Map<Room>(entityDTO);
                await _repository.Add(entity);
            }
            catch (DbUpdateException)
            {
                throw;
            }
        }

        public async Task<List<RoomDTO>> GetAll()
        {
            var results = _mapper.Map<List<RoomDTO>>(await _repository.GetAll());
            return results;
        }


        public async Task Remove(RoomDTO entityDTO)
        {
            if (entityDTO == null)
            {
                throw new ArgumentNullException(nameof(entityDTO));
            }
            try
            {
                await _repository.Delete(entityDTO.IdRoom);
            }
            catch (DbUpdateException)
            {
                throw;
            }
        }



        public async Task Update(RoomDTO entityDTO)
        {
            if (entityDTO == null)
            {
                throw new ArgumentNullException(nameof(entityDTO));
            }
            try
            {
                var entity = _mapper.Map<Room>(entityDTO);
                await _repository.Update(entity);
            }
            catch (DbUpdateException)
            {
                throw;
            }
        }

        Task<RoomDTO> IEntityLogic<RoomDTO>.GetByName(string name)
        {
            throw new NotImplementedException();
        }
    }
}
