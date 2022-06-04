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
    internal class RoomTypeLogic : IEntityLogic<RoomTypeDTO>
    {
        private readonly IHotelRepository<RoomType> _repository;
        private readonly IMapper _mapper;

        public RoomTypeLogic(IHotelRepository<RoomType> repository, IMapper mapper)
        {
            _repository = repository;
            _mapper = mapper;
        }

        public async Task Add(RoomTypeDTO entityDTO)
        {
            if (entityDTO == null)
            {
                throw new ArgumentNullException(nameof(entityDTO));
            }
            try
            {
                var entity = _mapper.Map<RoomType>(entityDTO);
                await _repository.Add(entity);
            }
            catch (DbUpdateException)
            {
                throw;
            }
        }

        public async Task<List<RoomTypeDTO>> GetAll()
        {
            var results = _mapper.Map<List<RoomTypeDTO>>(await _repository.GetAll());
            return results;
        }


        public async Task Remove(RoomTypeDTO entityDTO)
        {
            if (entityDTO == null)
            {
                throw new ArgumentNullException(nameof(entityDTO));
            }
            try
            {
                await _repository.Delete(entityDTO.IdRoomType);
            }
            catch (DbUpdateException)
            {
                throw;
            }
        }



        public async Task Update(RoomTypeDTO entityDTO)
        {
            if (entityDTO == null)
            {
                throw new ArgumentNullException(nameof(entityDTO));
            }
            try
            {
                var entity = _mapper.Map<RoomType>(entityDTO);
                await _repository.Update(entity);
            }
            catch (DbUpdateException)
            {
                throw;
            }
        }

        Task<RoomTypeDTO> IEntityLogic<RoomTypeDTO>.GetByName(string name)
        {
            throw new NotImplementedException();
        }
    }
}
